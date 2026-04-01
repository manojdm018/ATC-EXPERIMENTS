%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *s);
int yylex();
%}

%token IF ELSE WHILE ID NUM RELOP

%%
stmt: IF '(' cond ')' '{' stmt '}'
    | IF '(' cond ')' '{' stmt '}' ELSE '{' stmt '}'
    | WHILE '(' cond ')' '{' stmt '}'
    | ID '=' expr ';'
    ;

cond: expr RELOP expr ;

expr: ID | NUM | expr '+' expr | expr '-' expr ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}

int main() {
    printf("Enter control statements (if/while):\n");
    yyparse();
    printf("Control statement parsed correctly.\n");
    return 0;
}
