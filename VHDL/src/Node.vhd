library ieee;
use ieee.std_logic_1164.all;

entity Node is
  generic (
    t : integer;
  );
  port (
    clk : in std_logic;
    x : in integer;
    parent_active : in std_logic;
    l_active : out std_logic;
    r_active : out std_logic;
  );
end Node;

architecture behavioral of Node is
  signal comparison : std_logic := 0;

  process(clk)
  begin
    if rising_edge(clk) then
      comparison <= x_i <= t_i;
      l_active <= comparison and parent_active;
      r_active <= comparison and (not parent_active);
    end if;
  end process;
end behavioral;
