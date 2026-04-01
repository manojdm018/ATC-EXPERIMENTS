# ATC Experiments - Lab Activities

This repository contains Lex and Yacc programs for 10 lab activities, organized into separate folders.

## Experiments Index

1.  **[Experiment 1](./Experiment%201)**: Lex Program to Identify Tokens
2.  **[Experiment 2](./Experiment%202)**: Lex Program for Removing Comments
3.  **[Experiment 3](./Experiment%203)**: Lex Program to Count Lines, Words, and Characters
4.  **[Experiment 4](./Experiment%204)**: Lex Program to Validate Regular Expressions
5.  **[Experiment 5](./Experiment%205)**: Yacc Program for Arithmetic Expression Evaluation
6.  **[Experiment 6](./Experiment%206)**: Yacc Program to Check Grammar Ambiguity
7.  **[Experiment 7](./Experiment%207)**: Yacc Program for Constructing Abstract Syntax Tree (AST)
8.  **[Experiment 8](./Experiment%208)**: Lex + Yacc Program to Implement Control Statements Parser
9.  **[Experiment 9](./Experiment%209)**: C Program for DAG-based Optimization of a Basic Block
10. **[Experiment 10](./Experiment%2010)**: Code Generation Program (Simple Expression → Assembly)

## Environment Requirements
To compile and run these programs, you need:
- **Flex** (Lexical Analyzer Generator)
- **Bison** or **Yacc** (Parser Generator)
- **GCC** (C Compiler)

### Typical Compilation Flow
For Lex:
```bash
flex program.l
gcc lex.yy.c -o program
./program
```

For Yacc:
```bash
bison -d parser.y
flex lexer.l
gcc lex.yy.c parser.tab.c -o parser
./parser
```
