# Exercise-Calculator

This is a simple calculator program, written in C++, that evaluates an infix arithmetic expression. Through this exercise, I practices implementation of stacks and queues, and it helps me further understand these two data structures.


## Introduction

This program first converts an infix expression to a postfix one, and then evaluates it with a simple stack data structure. It handles invalid expressions, and specifically points out those with unbalanced paratheses.

### Input
- A sequence of characters composed of "0123456789+-*/()" (with length smaller than `BUF_SIZE` in `main.cpp`")

### Output
- Evaluated value, if it is a valid expression
- Prompt "Unbalanced Parantheses", if it is an invalid expression with unmatched left and right parantheses
- Prompt "Invalid Expression", if it is an invalid expression with other conditions

### Exmaples
Input | Output
------------ | -------------
100+2+33*2 | 168
(100+2+(33*2) | Unbalanced Parentheses
(100+2+(33*2))+- | Invalid Expression

## Installation

With Terminal on OSX or Linux

1. Clone this repository.
2. Change to the directory "Exercise-Calcualtor".
```Shell
$ cd ./Exercise-Calculator
```
3. Compile with `make`.
```Shell
$ make
```
4. Execute with `./calculator`.
```Shell
$ ./calculator
```

Besides, you may also compile and execute the program with any IDEs you preferred.


## Usage

On program execution, you may enter an arithmetic expression after the following prompt.
```
===== Press Ctrl+C to exit. =====
Valid input characters: 0123456789()+-*/
Enter an arithmetic expression within 100 characters:
```

Once you enter an expression and press Enter, it shows an output.
```
===== Press Ctrl+C to exit. =====
Valid input characters: 0123456789()+-*/
Enter an arithmetic expression within 100 characters: 
100+2+33*2
168
```

Press Ctrl+C to exit.

### Customization

You may change the length constraint of input characters by modifying the value of `BUF_SIZE` constant in `main.cpp`.
```C++
1 #include <iostream>                                                                                                           
2 #include "calculator.h"                                                         
3                                                                                 
4 using namespace std;                                                            
5                                                                                 
6 const size_t BUF_SIZE = 101;     
``` 
