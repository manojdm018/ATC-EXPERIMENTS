# Experiment 4: Lex Program to Validate Regular Expressions

## Problem Statement
Write a Lex program that validates different patterns using regular expressions (e.g., Email, Phone Number, Date).

## Source Code
- [validate_regex.l](validate_regex.l)

## How to Run
```bash
# Option 1: Lex Version
flex validate_regex.l
gcc lex.yy.c -o validate
./validate

# Option 2: Pure C Version
gcc main.c -o validate_c
./validate_c
```

## Actual Output
```text
Enter strings to validate (Email, Phone, Date):
user@example.com
Valid Email: user@example.com
+12345678901
Valid Phone Number: +12345678901
2024-04-01
Valid Date (YYYY-MM-DD): 2024-04-01
abc
Invalid Pattern: abc
```
