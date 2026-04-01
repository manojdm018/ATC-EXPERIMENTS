# Experiment 5: Arithmetic Expression Evaluation

## Problem Statement
Write a Yacc program to evaluate simple arithmetic expressions using a Lex tokenizer.

## Source Code
- [lexer.l](calc.l)
- [parser.y](calc.y)

## How to Run
```bash
# Option 1: Yacc Version
bison -d calc.y
flex lexer.l
gcc lex.yy.c calc.tab.c -o calc
./calc

# Option 2: Pure C Version
gcc main.c -o calc_c
./calc_c
```

## Actual Output
```text
Enter arithmetic expression:
10 + 5 * 2
Result: 20
```
