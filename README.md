# 42 Cursus - push_swap

## Info

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

- Status: waitinf for evaluation
- Result: n/a
- Observations: (null)

## Challenge

Sort stack `a`, with the help of stack `b`, using the smallest number of moves and a limited set of operations.

## Game rules

- The game is composed of 2 stacks named `a` and `b`.
- To start with:
  - `a` contains a random numbe of either positive or negative numbers without any duplications, passed via terminal arguments (you must handle wrong input).
  - `b` is empty.
- The goal is to sort in ascending order numbers into stack a.
- To do this you have the following operations at your disposal:
  - `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - `ss` : `sa` and `sb` at the same time.
  - `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  - `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  - `rr` : `ra` and `rb` at the same time.
  - `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
  - `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
  - `rrr` : `rra` and `rrb` at the same time.
- At the end stack `b` must be emtpy and all integers must be sorted in ascending order in stack `a`.

My implementation of the operations in a doubly linked list:
![Operations diagram](https://github.com/izenynn/push_swap/blob/main/diagrams/operations_diagram.png)

## Aproach

I take different aproachs depending of the size of the stack.

- 1 numbers
Allways sorted :D

- 2 numbers
Easy, `sa` if second one if bigger than the first.

- 3 numbers
For 3 numbers it is easy, they are only 5 possible solutions, so a few if else was all I needed:

![Sort three diagram](https://github.com/izenynn/push_swap/blob/main/diagrams/sort_three_diagram.png)

- 3 ~ 5 numbers
This is when things get darker, to sort 4 or 5 arguments I just push 1 or 2 numbers from stack `a` to `b`, making sure I left 3 arguments on `a`, so now I can sort those 3 numbers with the sort 3 function. Once sorted I push back to stack `a` the numbers on stack `b`, making sure I push it in the correct positions, how? I just rotate the stack with `ra` and `rra`, and push the number back when I can push it in the correct position. When done I just rotate the list until the smallest number is on top.

- 5 ~ inf.
After trying different algorithms and seeing them in action, I decided to use a chunk based one. Making a long history sort, I divide stack `a` into "chunks", for example:
	- 0  ~ 19: chunk 1
	- 20 ~ 39: chunk 2
	- 40 ~ 59: chunk 3
	- 60 ~ 79: chunk 4
	- 80 ~ 99: chunk 5

Now, I rotate stack `a` searching for numbers in chunk 1, once I found one, I push it to `b`. Once all the stack is pushed, I move to the next one, and so on until stack `a` is empty.
To push the elements back to stack `a` I just check for the bigger one, rotate with `ra` or `rra`, depending on wich one takes less moves, and push the element back, one by one, from bigger to smaller, and since they are sorted by chunks, I will not need to rotate too much to find the next one.

## How to use

- Compile using make

```sh
make
```

- Execute `push_swap` with the stack `a` as parameter

```sh
./push_swap 4 3 1 0 2
```

- You can use other commands like `seq` and `sort -R` to generate a random list, and make it complex

```sh
ARG=`seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '`; ./push_swap $ARG
```

- If you can to use a checker, just use it as follows:

```sh
./push_swap 4 3 1 0 2 | ./push_swap_tester/checkers/checker_OS 4 3 1 0 2
```

- or

```sh
ARG="4 3 1 0 2"; ./push_swap $ARG | ./checker $ARG
```

- Checkers are cool but I would recommend you trying my tester, `push_swap_tester`, it is a gitsubmodule in this repo, more info about how to use it in the `push_swap_tester`
[push_swap_tester repo](https://github.com/izenynn/push_swap_tester)

## Checker

To do this project we were given two checkers, one for Mac and another one for Linux, but what if we code our own checker?

This is the bonus part of the project, `checker` is a program which will get as an argument the stack a formatted as a list of integers (just copy paste the `push_swap` argument). It will parse the arguments and create the stack, just like `push_swap`, and it will test your `push_swap` works, let me explain.

The `checker` program will take the output of `push_swap`, and using `ft_get_next_line` ([get_next_line repo](https://github.com/izenynn/get_next_line)), it will copy the movements, and when finished, return `OK` if the stack is sorted, or `KO` if not.

Of course, `checker` also handle errors, like no arguments, invalid arguments, wrong push_swap output (something different than a operation), etc.

### How to use `checker`

- Compile `checker` with make

```sh
make checker
```

- Now just use it as the other checkers

```sh
./push_swap 3 2 1 0 4 | ./checker 3 2 1 0 4
```

- or

```sh
ARG="3 2 1 0 4"; ./push_swap $ARG | ./checker $ARG
```

Or of course you can test it with my tester [push_swap_tester repo](https://github.com/izenynn/push_swap_tester)

##
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/contains-tasty-spaghetti-code.svg)](https://forthebadge.com)
