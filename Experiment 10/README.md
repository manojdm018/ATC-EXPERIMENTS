# Experiment 10: Code Generation (Expression to Assembly)

## Problem Statement
Write a Yacc program to generate target assembly code (simple MOVE, ADD, SUB instructions) for arithmetic expressions.

## Source Code
- [code_gen.y](code_gen.y)

## How to Run
```bash
bison -d code_gen.y
flex lexer.l
gcc lex.yy.c code_gen.tab.c -o codegen
./codegen
```

## Actual Output
```text
Enter expression to generate assembly:
a + b * c

MOV R0, b
MUL R0, c
MOV t0, R0
MOV R0, a
ADD R0, t0
MOV t1, R0

Code Generation Finished
```
