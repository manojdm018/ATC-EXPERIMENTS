# Experiment 5: Arithmetic Expression Evaluation

## Problem Statement
Write a Yacc program to evaluate simple arithmetic expressions using a Lex tokenizer.

## Source Code
- [lexer.l](calc.l)
- [parser.y](calc.y)

## How to Run
```bash
bison -d calc.y
flex calc.l
gcc lex.yy.c calc.tab.c -o calc
./calc
```

## Actual Output
```text
Enter arithmetic expression:
10 + 5 * 2
Result: 20
```
