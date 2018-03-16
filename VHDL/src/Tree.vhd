architecture behavioral of BDT is
component Node is
  generic ( t_i : integer )
 port (
    clk : in std_logic;
  x_i : in integer;
  parent_active : in std_logic;
 l_active : out std_logic;
  r_active : out std_logic;
  );
  end component;signal node_0_1_parent_active : std_logic;
signal node_0_1_x : integer;
signal node_0_1_r_active : std_logic;
signal node_0_1_l_active : std_logic;
signal node_0_2_parent_active : std_logic;
signal node_0_2_x : integer;
signal node_0_2_r_active : std_logic;
signal node_0_2_l_active : std_logic;
signal node_0_3_parent_active : std_logic;
signal node_0_3_x : integer;
signal node_0_3_r_active : std_logic;
signal node_0_3_l_active : std_logic;
signal node_0_4_parent_active : std_logic;
signal node_0_4_x : integer;
signal node_0_4_r_active : std_logic;
signal node_0_4_l_active : std_logic;
signal node_0_5_parent_active : std_logic;
signal node_0_5_x : integer;
signal node_0_5_r_active : std_logic;
signal node_0_5_l_active : std_logic;
signal node_0_6_parent_active : std_logic;
signal node_0_6_x : integer;
signal node_0_6_r_active : std_logic;
signal node_0_6_l_active : std_logic;
signal node_0_7_parent_active : std_logic;
signal node_0_7_x : integer;
signal node_0_7_r_active : std_logic;
signal node_0_7_l_active : std_logic;
signal node_0_8_parent_active : std_logic;
signal node_0_8_x : integer;
signal node_0_8_r_active : std_logic;
signal node_0_8_l_active : std_logic;
signal node_0_9_parent_active : std_logic;
signal node_0_9_x : integer;
signal node_0_9_r_active : std_logic;
signal node_0_9_l_active : std_logic;
signal node_0_10_parent_active : std_logic;
signal node_0_10_x : integer;
signal node_0_10_r_active : std_logic;
signal node_0_10_l_active : std_logic;
signal node_0_11_parent_active : std_logic;
signal node_0_11_x : integer;
signal node_0_11_r_active : std_logic;
signal node_0_11_l_active : std_logic;
node_0_1: Node
generic map ( t => 0.0648016184568)
port map (
clk => clk;
x => node_0_1_x;
parent_active => 1;
l_active => node_0_1_l_active;
r_active => node_0_1_r_active;
);
node_0_2: Node
generic map ( t => -0.519760906696)
port map (
clk => clk;
x => node_0_2_x;
parent_active => node_0_1_l_active;
l_active => node_0_2_l_active;
r_active => node_0_2_r_active;
);
node_0_3: Node
generic map ( t => -2.0)
port map (
clk => clk;
x => node_0_3_x;
parent_active => node_0_2_l_active;
l_active => node_0_3_l_active;
r_active => node_0_3_r_active;
);
node_0_4: Node
generic map ( t => -0.0867137461901)
port map (
clk => clk;
x => node_0_4_x;
parent_active => node_0_2_r_active;
l_active => node_0_4_l_active;
r_active => node_0_4_r_active;
);
node_0_5: Node
generic map ( t => -2.0)
port map (
clk => clk;
x => node_0_5_x;
parent_active => node_0_4_l_active;
l_active => node_0_5_l_active;
r_active => node_0_5_r_active;
);
node_0_6: Node
generic map ( t => -2.0)
port map (
clk => clk;
x => node_0_6_x;
parent_active => node_0_4_r_active;
l_active => node_0_6_l_active;
r_active => node_0_6_r_active;
);
node_0_7: Node
generic map ( t => 1.46243071556)
port map (
clk => clk;
x => node_0_7_x;
parent_active => node_0_1_r_active;
l_active => node_0_7_l_active;
r_active => node_0_7_r_active;
);
node_0_8: Node
generic map ( t => 0.202279090881)
port map (
clk => clk;
x => node_0_8_x;
parent_active => node_0_7_l_active;
l_active => node_0_8_l_active;
r_active => node_0_8_r_active;
);
node_0_9: Node
generic map ( t => -2.0)
port map (
clk => clk;
x => node_0_9_x;
parent_active => node_0_8_l_active;
l_active => node_0_9_l_active;
r_active => node_0_9_r_active;
);
node_0_10: Node
generic map ( t => -2.0)
port map (
clk => clk;
x => node_0_10_x;
parent_active => node_0_8_r_active;
l_active => node_0_10_l_active;
r_active => node_0_10_r_active;
);
node_0_11: Node
generic map ( t => -2.0)
port map (
clk => clk;
x => node_0_11_x;
parent_active => node_0_7_r_active;
l_active => node_0_11_l_active;
r_active => node_0_11_r_active;
);
