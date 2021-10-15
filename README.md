# 42 Cursus - push_swap

## Info

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

- Status: unfinished
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

## Aproach

TODO

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
ARG=`seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '` && ./push_swap $ARG
```

- If you can to use a checker, just use it as follows:

```sh
./push_swap 4 3 1 0 2 | ./push_swap_tester/checkers/checker_OS 4 3 1 0 2
```

- or

```sh
ARG="4 3 1 0 2"; ./push_swap $ARG | ./checker $ARG
```

- Checkers are cool but I would recommend you trying my tester, `push_swap_tester`, it is a gitsubmodule in this repo, more info about how to use it in the `push_swap_tester` repo page: [link to repo](https://github.com/izenynn/push_swap_tester)

## Checker

To do this project we were given two checkers, one for Mac and another one for Linux, but what if we code our own checker?

This is the bonus part of the project, `checker` is a program which will get as an argument the stack a formatted as a list of integers (just copy paste the `push_swap` argument). It will parse the arguments and create the stack, just like `push_swap`, and it will test your `push_swap` works, let me explain.

The `checker` program will take the output of `push_swap`, and using `ft_get_next_line` ([link to repo](https://github.com/izenynn/get_next_line)), it will copy the movements, and when finished, return `OK` if the stack is sorted, or `KO` if not.

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

or of course you can test it with my tester :)
[Link to tester repo](https://github.com/izenynn/push_swap_tester)

##
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/contains-tasty-spaghetti-code.svg)](https://forthebadge.com)
