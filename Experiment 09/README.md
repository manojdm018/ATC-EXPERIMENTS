# Experiment 9: DAG-based Optimization

## Problem Statement
Implement a C program for DAG-based optimization of a basic block (identifying common subexpressions).

## Source Code
- [dag_optimizer.c](dag_optimizer.c)

## How to Run
```bash
gcc dag_optimizer.c -o optimize
./optimize
```

## Actual Output
```text
Enter number of expressions: 3
Enter expressions (e.g., t1 = a + b):
t1 = a + b
t2 = c * d
t3 = a + b

Optimized Code (using DAG approach):
t1 = a + b
t2 = c * d
t3 = t1
```
