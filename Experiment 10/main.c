#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *pos;
int tmp_count = 0;

char* parse_E();
char* parse_T();
char* parse_F();

char* new_tmp() {
    char *t = malloc(10);
    sprintf(t, "t%d", tmp_count++);
    return t;
}

char* parse_E() {
    char *res = parse_T();
    while(*pos == '+' || *pos == '-') {
        char op = *pos++;
        char *right = parse_T();
        char *t = new_tmp();
        printf("MOV R0, %s\n", res);
        printf("%s R0, %s\n", (op == '+') ? "ADD" : "SUB", right);
        printf("MOV %s, R0\n", t);
        res = t;
    }
    return res;
}

char* parse_T() {
    char *res = parse_F();
    while(*pos == '*' || *pos == '/') {
        char op = *pos++;
        char *right = parse_F();
        char *t = new_tmp();
        printf("MOV R0, %s\n", res);
        printf("%s R0, %s\n", (op == '*') ? "MUL" : "DIV", right);
        printf("MOV %s, R0\n", t);
        res = t;
    }
    return res;
}

char* parse_F() {
    char *buf = malloc(20); int i=0;
    if(isdigit(*pos)) {
        while(isdigit(*pos)) buf[i++] = *pos++;
    } else if(isalpha(*pos)) {
        while(isalnum(*pos)) buf[i++] = *pos++;
    }
    buf[i] = '\0';
    return buf;
}

int main() {
    char input[100];
    printf("Enter expression for code generation: ");
    scanf("%s", input);
    pos = input;
    parse_E();
    printf("\nCode Generation Finished\n");
    return 0;
}
