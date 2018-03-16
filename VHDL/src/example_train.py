from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
from sklearn.ensemble import GradientBoostingClassifier
import FastBDT

X, y = make_moons(noise=0.3, random_state=0)

bdt =  GradientBoostingClassifier()
X_train, X_test, y_train, y_test =\
  train_test_split(X, y, test_size=.4, random_state=42)

bdt.fit(X_train, y_train)

tree = bdt.estimators_[0][0].tree_
f = tree.feature
v = tree.value
t = tree.threshold
cl = tree.children_left
cr = tree.children_right

basetree = FastBDT.BaseTree(f, cl, cr, t, v)
fasttree = FastBDT.Tree(basetree)
trees = [fasttree]
with open("Tree.vhd", "w") as file:
  FastBDT.writeEnsemble(file, trees)
