# push_swap
## The school 42 project of algorithms branch
##### First, you need to write an algorithm that will sort the numbers using two stacks and certain commands.
##### Second, you need to write a program that will check whether the numbers are correctly sorted by your algorithm.
##### I also wrote a program that will generate random and non-repeating numbers. 

# Game rules
* The game is composed of 2 stacks named a and b.
* To start with:
	* a contains a random number of either positive or negative numbers without any duplicates.
	* b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:
	* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
	* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
	* ss : sa and sb at the same time.
	* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
	* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
	* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
	* rr : ra and rb at the same time.
	* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
	* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
	* rrr : rra and rrb at the same time.
# push_swap program
### the program finds the minimum number of commands and outputs them
## example:
![](https://github.com/Dude-Rocker/push_swap/blob/master/examples/ps_xmpl.png)
# checker program
### my checker several flags are implemented, namely:
* ***-v*** - visual mode
	* ***-s*** - step by step mode
	* ***-o*** - displays operations
* ***-c*** - color visualization and output of the result
* ***-d*** - debug mode
* ***-n*** - displays the number of commands used

## few examples:
### without flags
![](https://github.com/Dude-Rocker/push_swap/blob/master/examples/check.png)
### debug mode
![](https://github.com/Dude-Rocker/push_swap/blob/master/examples/debug.gif)
### flags: -n -c
![](https://github.com/Dude-Rocker/push_swap/blob/master/examples/checkcolor.png)
### visual mode all flags are on
![](https://github.com/Dude-Rocker/push_swap/blob/master/examples/visual.gif)
# randomaizer program
### This program generates the number of numbers specified in the argument, and enters them into push_swap and inserts its result into the checker
## example:
![](https://github.com/Dude-Rocker/push_swap/blob/master/examples/randomaizer.png)
