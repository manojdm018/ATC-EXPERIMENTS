%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *s);
int yylex();
int temp_count = 0;
char* new_temp();
%}

%union {
    char name[20];
}

%token <name> ID NUM
%type <name> E

%left '+' '-'
%left '*' '/'

%%
S: E { printf("\nCode Generation Finished\n"); exit(0); }
 ;

E: E '+' E { 
    char *t = new_temp();
    printf("MOV R0, %s\n", $1);
    printf("ADD R0, %s\n", $3);
    printf("MOV %s, R0\n", t);
    strcpy($$, t);
   }
 | E '-' E { 
    char *t = new_temp();
    printf("MOV R0, %s\n", $1);
    printf("SUB R0, %s\n", $3);
    printf("MOV %s, R0\n", t);
    strcpy($$, t);
   }
 | E '*' E { 
    char *t = new_temp();
    printf("MOV R0, %s\n", $1);
    printf("MUL R0, %s\n", $3);
    printf("MOV %s, R0\n", t);
    strcpy($$, t);
   }
 | NUM { strcpy($$, $1); }
 | ID  { strcpy($$, $1); }
 ;

%%

char* new_temp() {
    char *t = (char*)malloc(10);
    sprintf(t, "t%d", temp_count++);
    return t;
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expression to generate assembly:\n");
    yyparse();
    return 0;
}
