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

The checker program reads a random list of integers from the stdin, then it reads the instructions finished by \n, and checks to see if they are sorted.

The push_swap program calculates the instructions to sort the integers, then print instructions on stdout.

flag -f : read instructions from a file(checker) and write instructions on a file(push_swap)
flag -v : print stack at each step

Ex:
./push_swap 2 6 9 -1
./push_swap "2 6 9 -1"
./push_swap 2 6 9 -1 -v -f
 ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
