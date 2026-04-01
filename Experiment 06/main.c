#include <stdio.h>
#include <string.h>

/* Simple demo of ambiguity: E -> E + E | E * E | id */
int is_ambiguous(char *exp) {
    if(strstr(exp, "+") && strstr(exp, "*")) return 1;
    return 0;
}

int main() {
    char exp[100];
    printf("Enter expression (e.g. a+b*c): ");
    scanf("%s", exp);
    if(is_ambiguous(exp)) {
        printf("The expression is ambiguous for grammar E -> E+E | E*E | id\n");
        printf("Possible Parse 1: (a+b)*c\n");
        printf("Possible Parse 2: a+(b*c)\n");
    } else {
        printf("Parsed successfully.\n");
    }
    return 0;
}
