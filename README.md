# ATC Experiments - Lab Activities

This repository contains Lex and Yacc programs for 10 lab activities, organized into separate folders.

## Experiments Index

1.  **[Experiment 01](./Experiment%2001)**: Lex Program to Identify Tokens
2.  **[Experiment 02](./Experiment%2002)**: Lex Program for Removing Comments
3.  **[Experiment 03](./Experiment%2003)**: Lex Program to Count Lines, Words, and Characters
4.  **[Experiment 04](./Experiment%2004)**: Lex Program to Validate Regular Expressions
5.  **[Experiment 05](./Experiment%2005)**: Yacc Program for Arithmetic Expression Evaluation
6.  **[Experiment 06](./Experiment%2006)**: Yacc Program to Check Grammar Ambiguity
7.  **[Experiment 07](./Experiment%2007)**: Yacc Program for Constructing Abstract Syntax Tree (AST)
8.  **[Experiment 08](./Experiment%2008)**: Lex + Yacc Program to Implement Control Statements Parser
9.  **[Experiment 09](./Experiment%2009)**: C Program for DAG-based Optimization of a Basic Block
10. **[Experiment 10](./Experiment%2010)**: Code Generation Program (Simple Expression → Assembly)

## Environment Requirements
To compile and run these programs, you need:
- **Flex** (Lexical Analyzer Generator)
- **Bison** or **Yacc** (Parser Generator)
- **GCC** (C Compiler)

## 💡 Dual Implementation
Each experiment (except Exp 09, which is pure C) now includes two ways to run:
1. **Tool-based Version**: Uses Flex and Bison (standard for compiler labs).
2. **Pure C Version**: A manual implementation (`main.c`) that can be compiled with just `gcc`. No special tools required!

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
