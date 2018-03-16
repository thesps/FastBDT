'''Utilities to write a VHDL implementation of a trained BDT'''

class Port:
'''Class for VHDL component Ports'''
  def __init__(self, label, direction, dataType):
    self._label = label
    self._direction = direction
    self._type = dataType

class Signal:
'''Class for VHDL component signals'''
  def __init__(self, label, dataType):
    self._label = label
    self._type = dataType

  def declaration(self, initValue=None):
    ''' return the signal declaration '''
    initString = ""
    if initValue is not None:
      initString = " => " + str(initValue)
    return "signal " + self._label + " : " + self._type + initString + ";\n"

def connect(l, r):
  if isinstance(l, Port) and isinstance(r, Signal):
    return l._label + " => " + r._label + ";\n"

clk_sig = Signal("clk", "std_logic");

class BaseTree:
  '''A Decision Tree represented in the scikit-learn style format'''
  def __init__(self, features, childrenLeft, childrenRight, thresholds, values):
    self._features = features
    self._childrenLeft = childrenLeft
    self._childrenRight = childrenRight
    self._thresholds = thresholds
    self._values = values

class Tree:
  n = 0
  def __init__(self, baseTree):
    self._n = Tree.n
    Tree.n += 1
    self._baseTree = baseTree
    self._nodes = constructTree(baseTree, self)

def constructTree(baseTree, tree):
  iN = 0;
  nodes = []
  n = Node(None, iN, tree, baseTree._features[iN], baseTree._thresholds[iN], baseTree._values[iN])
  nodes.append(n)
  done = False
  while not done:
    if (n._i == 0) and (n._childLeft is not None) and (n._childRight is not None):
      # At the root node with booth children, so done
      done = True
      break
    if ((baseTree._childrenLeft[n._i] == -1) or ((n._childLeft is not None) and (n._childRight is not None))):
      # Need to ascend
      n = n._parent
    lastN = n
    n = Node.addChildLeftFirst(n, tree)
    if(n != lastN):
      nodes.append(n) 
  return nodes
  
 
class Node:
'''Decision node. Stores references to parent and child nodes in tree, and is assigned global component and signal names for VHDL'''
  n = 0
  _ports = {"clk":Port("clk", "in", "std_logic"), "x":Port("x", "in", "integer"),
            "parent_active":Port("parent_active", "in", "std_logic"),
            "l_active":Port("l_active", "out", "std_logic"),
            "r_active":Port("r_active", "out", "std_logic")}
  def __init__(self, parent, i, tree, x, t, v):
    Node.n += 1
    self._x = x
    self._t = t
    self._parent = parent
    self._childLeft = None
    self._childRight = None
    self._i = i
    self._n = Node.n
    self._label = nodeLabel(tree, self)
    self._x_sig = Signal(self._label + "_x", "integer")
    self._parent_active_sig = Signal(self._label + "_parent_active", "std_logic")
    self._l_active_sig = Signal(self._label + "_l_active", "std_logic")
    self._r_active_sig = Signal(self._label + "_r_active", "std_logic")
    self._signals = {"x":self._x_sig,"parent_active":self._parent_active_sig,
                     "l_active":self._l_active_sig, "r_active":self._r_active_sig}

  def isLeftChild(self):
    if self._parent is not None:
      return self._parent._childLeft == self
    return False

  def isRoot(self):
    return self._parent is None

  def addChildLeftFirst(parent, tree):
    iC = 0
    newNode = parent
    if parent._childLeft is None:
      iC = tree._baseTree._childrenLeft[parent._i]
      if iC != -1:
        newNode = Node(parent, iC, tree, tree._baseTree._features[iC], tree._baseTree._thresholds[iC], tree._baseTree._values[iC])
        parent._childLeft = newNode
    elif parent._childRight is None:
      iC = tree._baseTree._childrenRight[parent._i]
      if iC != -1:
        newNode = Node(parent, iC, tree, tree._baseTree._features[iC], tree._baseTree._thresholds[iC], tree._baseTree._values[iC])
        parent._childRight = newNode
    return newNode

def nodeLabel(tree, node):
  return "node_" + str(tree._n) + "_" + str(node._n)

def writeEnsemble(f, trees):
'''Write the ensemble VHDL implementation to file'''
  f.write("architecture behavioral of BDT is\n")
  # Declare the Node component
  f.write(nodeHeader)
  # Declare all signals for all Nodes
  for tree in trees:
    for node in tree._nodes:
      for signal in node._signals:
        f.write(node._signals[signal].declaration())

  for tree in trees:
    writeTree(f, tree)

def writeTree(f, tree):
'''Instantiate Node objects for the decision tree with appropriate threshold generics and signal connectivity'''
    for node in tree._nodes:
      f.write(nodeLabel(tree, node) + ": Node\n")
      f.write("generic map ( t => " + str(node._t) + ")\n")
      f.write("port map (\n")
      f.write(connect(node._ports["clk"], clk_sig))
      f.write(connect(node._ports["x"], node._signals["x"]))
      if node.isRoot():
        f.write("parent_active => 1;\n")
      elif node.isLeftChild():
        f.write(connect(node._ports["parent_active"], node._parent._signals["l_active"]))
      else:
        f.write(connect(node._ports["parent_active"], node._parent._signals["r_active"]))
      f.write(connect(node._ports["l_active"], node._signals["l_active"]))
      f.write(connect(node._ports["r_active"], node._signals["r_active"]))
      f.write(");\n")

nodeHeader = "component Node is\n  generic ( t_i : integer )\n port (\n    clk : in std_logic;\n"
nodeHeader += "  x_i : in integer;\n  parent_active : in std_logic;\n l_active : out std_logic;\n"
nodeHeader += "  r_active : out std_logic;\n  );\n  end component;"
