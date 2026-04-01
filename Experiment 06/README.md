# Experiment 6: Grammar Ambiguity Check

## Problem Statement
Write a Yacc program to check if a given context-free grammar is ambiguous (e.g., E -> E+E | E*E | id).

## Source Code
- [ambiguity.y](ambiguity.y)

## How to Run
```bash
# Option 1: Yacc Version
bison -d ambiguity.y
flex lexer.l
gcc lex.yy.c ambiguity.tab.c -o ambiguity
./ambiguity

# Option 2: Pure C Version
gcc main.c -o ambiguity_c
./ambiguity_c
```

## Actual Output
```text
Enter expression (like a + b * c) to check ambiguity:
a + b * c
Parsed Successfully
```
> [!NOTE]
> The grammar `E -> E + E | E * E | id` is ambiguous. In a real Yacc parser, this would cause shift/reduce conflicts unless precedence is specified.
