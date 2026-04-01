# Experiment 1: Lex Program to Identify Tokens

## Problem Statement
Write a Lex program to identify keywords, identifiers, numbers, and operators from a given C-like input code.

## Source Code
- [tokens.l](tokens.l)

## How to Run
```bash
flex tokens.l
gcc lex.yy.c -o tokens
./tokens
```

## Actual Output
![Experiment 1 Output](output.png)
