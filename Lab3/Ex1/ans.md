# What do the .data, .word, .text directives mean (i.e. what do you use them for)? Hint: think about the 4 sections of memory.

.data 声明以下初始化数据段 static data
.word 定义,分配空间 static data
.test 声明以下代码段 code

# Run the program to completion. What number did the program output? What does this number represent?

34, the 9th element of Fibonacci sequence.

# At what address is n stored in memory? Hint: Look at the contents of the registers.



# Without using the “Edit” tab, have the program calculate the 13th fib number (0-indexed) by manually modifying the value of a register. You may find it helpful to first step through the code. If you prefer to look at decimal values, change the “Display Settings” option at the bottom.

当运行到beq指令时，将register中t3(x28)值由 9 改为 13即可