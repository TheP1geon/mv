# Mirtual Vachine (mv)
A ***very*** simple virtual machine written in C. Inspired by Tsoding.

[Writing VM for my Lisp in C — Day 1](https://www.youtube.com/watch?v=0irYsCYuZws&list=PLpM-Dvs8t0VY73ytTCQqgvgCWttV3m8LM) 

[Tsoding](https://www.youtube.com/@TsodingDaily)

# Quick Start
```console
$ ./mv <example program>
```
# Instructions

    add, sub, div, mod, mult 
        Pops the top two numbers off the stack and pushes the result

    inc, dec
        increments, or decrements, the stack at that index
        
        if no index is provided the top of the stack is updated
    
    dupe
        pushes the value at the index provided

    push
        pretty self-explanatory

    push_lit
        pushes the literal (ascii) everything after the instruction

    mov
        if only one paramter is provided, the value at that register (zero based) is pushed to that stack
        
        if two parameters are provided, the second value is put into the register of the first parameter

    pop
        if a paramter is provided, the top of the stack is popped into that register
        
        if no paramter is passed, the top is just popped

    jmp (and all the variants)
        push 0
        push 1
        jmp 0

        all jump instructions take the jump-point as the first parameter

        the other jump options take what you're comparing the top of the stack with and only jumping if that is true

    dump
        prints the stack as numbers
    
    print
        prints the ascii representation of the stack

# Examples:
## count-to-10
Prints the first 10 natural numbers

```
push 0

dupe 0
inc 0

jmp_neq 1 10
dump
```
--------------
Output:
```
--------------
0
1
2
3
4
5
6
7
8
9
10
--------------
```

## fact
Calculates the factorial of the number in register 0

```
mov 0 5

mov 0
dec 0
pop 9

mov 0

dupe 0
dec 0
jmp_neq 5 0
pop

mov 9

pop 9
mult
mov 9
dec 0
jmp_neq 10 0
pop

dump
```
--------------
Output:
```
--------------
120
--------------
```

## fib
Calculates the first 15 fibonacci sequence

``` Code  
push 0
push 1
push 0

pop 9

dupe 1
dupe 1
add

mov 9
inc 0
jmp_lt 3 15
pop
dump
```
--------------
Output:
```
--------------
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
--------------

```

## hello world
Prints hello world

``` 
push_lit Hello, World!
pop

print
```
--------------
Output:
```
--------------
Hello, World!
--------------
```

## squares
```
mov 0 1
push 0

pop 9

mov 0
mov 0
mult
mov 0
inc 0
pop 0

mov 9
inc 0
jmp_lt 2 10

pop
dump
```
--------------
Output:
``` 
--------------
1
4
9
16
25
36
49
64
81
100
--------------
```

## Abc
```
push A

dupe 0
push 32
add

jmp_eq 11 z

push 32

push 32
dupe 2
sub

inc 0

jmp_lteq 1 Z

print
```
--------------
Output:
```
--------------
Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz
--------------
```

# NOTE:
comments are not natively supported
