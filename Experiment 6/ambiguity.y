%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *s);
int yylex();
%}

%token ID
/* Removing precedence makes this grammar ambiguous */
%%
S: E { printf("Parsed Successfully\n"); }
 ;
E: E '+' E 
 | E '*' E
 | '(' E ')'
 | ID
 ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Grammar Error: %s\n", s);
}

int main() {
    printf("Enter expression (like a + b * c) to check ambiguity:\n");
    yyparse();
    return 0;
}
