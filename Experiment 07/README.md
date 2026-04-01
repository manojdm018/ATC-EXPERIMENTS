# Experiment 7: Constructing Abstract Syntax Tree (AST)

## Problem Statement
Write a Yacc program to construct an Abstract Syntax Tree (AST) for a given arithmetic expression.

## Source Code
- [ast.y](ast.y)

## How to Run
```bash
bison -d ast.y
flex lexer.l
gcc lex.yy.c ast.tab.c -o ast
./ast
```

## Actual Output
```text
Enter expression to build AST:
a + b * c

Abstract Syntax Tree Structure:
+
  a
  *
    b
    c
```
