%{
#include <stdio.h>
%}

%%
"int"|"float"|"if"|"else"|"while"|"return"   { printf("Keyword: %s\n", yytext); }

[0-9]+                                      { printf("Number: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                      { printf("Identifier: %s\n", yytext); }

[+\-*/=]                                    { printf("Operator: %s\n", yytext); }

[ \t\n]                                     ;  // ignore spaces

.                                           { printf("Unknown: %s\n", yytext); }
%%

int main() {
    printf("Enter code:\n");
    yylex();
    return 0;
}