# Experiment 8: Control Statements Parser

## Problem Statement
Implement a parser for control statements (if-else, while) using Lex and Yacc.

## Source Code
- [control_flow.y](control_flow.y)

## How to Run
```bash
# Option 1: Lex+Yacc Version
bison -d control_flow.y
flex lexer.l
gcc lex.yy.c control_flow.tab.c -o parser
./parser

# Option 2: Pure C Version
gcc main.c -o parser_c
./parser_c
```

## Actual Output
```text
Enter control statements (if/while):
if (a > b) { x = 10; }
Control statement parsed correctly.
```
