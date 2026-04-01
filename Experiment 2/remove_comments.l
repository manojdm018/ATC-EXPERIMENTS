%{
#include <stdio.h>
%}

%%
"//".*                      ;   /* Skip single-line comments */

"/*"([^*]|\*+[^*/])*\*+"/"   ;   /* Skip multi-line comments */

.|\n                        { printf("%s", yytext); }
%%

int main() {
    printf("Enter code with comments (will output code without comments):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
