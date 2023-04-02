#### practice 1

propagation delay of an adder block  : 45ns
propagation delay of MUX 	     : 20ns
ropagation delay of a shifters block :  5ns
register CLK-to-Q delay 	     : 10ns
setup time 			     : 10ns
hold time 			     :  5ns


##### move and add
max(MUX+adder, shifter) = max(45 + 20, 5) = 65 ns
delay of the move_and_add part	     : 65ns


##### non pipelined
$T_{clk} \leq setup + t_{cd} + t_{pcq}$
$T_{clk} \leq 10 + 65 + 10 = 85ns$
$(T_clk)_{min} = 85ns$
$(f_clk)_{max} = 0.0118 GHz$
