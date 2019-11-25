

# Push_swap
42 School project

Sort a random list of integers using the smallest number of moves, with 2 stacks (A and B), and a limited set of instructions.

Instructions allowed :
ra - rotate stack A (send top number on stack to bottom)
rb - rotate stack B (send top number on stack to bottom)
rr - rotate both stack A and B at the same time
rra - counter-rotate stack A (send bottom number of stack to top)
rrb - counter-rotate stack B (send bottom number of stack to top)
rrr - counter-rotate stack A and stack B at the same time
sa - swap top two numbers at top of stack A
sb - swap top two numbers at top of stack B
pa - push top element from stack A onto stack B
pb - push stack B

Usage :
Run make
create two programs: checker and push_swap.

The checker program reads a random list of integers from the stdin,
then it reads the instructions finished by \n(Ctrl + D when all instructions given),  and checks to see if they are sorted.

The push_swap program calculates the instructions to sort the integers, then print instructions on stdout.

flag -f : read instructions from a file(for checker) and write instructions on a file(for push_swap)
flag -v : print stack at each step
flag -c : print last move in color

Ex:
./checker 2 1 3
sa
<Ctrl + D>

./push_swap 2 6 9 -1
./push_swap "2 6 9 -1"
./push_swap 2 6 9 -1 -v -f -v
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG


Algorithm
1. Repalce the integers by a list of consecutive numbers, and creat a dictionary
Ex :
Origin Index Array: -1 0 1000 3
Replaced by 	  : 0  1  3   2

This allows an easier calculate, later when print, with dictionary, we find the origin number to print

2. Go through stack to find best mark head before execute any instruction

Objectif : find the best mark head to keep Maximum de int on stack A

head is the integer from which we start marking, for integer below,
if it is bigger than the last one, we mark KEEP to keep it on stack A,
else we mark OUT to push it to stack B

EX:
if mark head is 0

1 OUT
7 KEEP
0 KEEP
2 KEEP
5 OUT
3 KEEP
4 KEEP
keep_nb of head 0 is = 5

current_head = 0
best_head = 0;
best_keep_nb = 0;
for all the integer value on stack A
	set integer as head
	find the head which has the highest keep_nb

3. mark which integer goes to b with given best_head
malloc an array
Index of array corresponds to value of int
Ex :  if marks[5] = TRUE,  value 5 stays in stack A
Ex :  if marks[4] = FALSE, value 4 will go to stak B

4. push certains integers to stack b
The number of integers going to be pushed to be will be: to_b_nb = total length of stack A - keep_nb

while (to_b_nb > 0)
	while (top value of stack A has mark TRUE)
		ra() or rra() // make a copy of stack to test, then decide to do ra() or rra()
	pb()
	to_b_nb--


5. Push all the int on stack B back to stack A

Calculate for each int on stack B:
steps needed for rotate b + rotate a + pa()

Choose the best int then push.
if it need to rotate b and a in the same direction,
it will do rr() or rrr() to optimise.

Keep doing this until stak B is empty
