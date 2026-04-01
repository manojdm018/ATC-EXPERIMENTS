%{
#include <stdio.h>
%}

%%
[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} { printf("Valid Email: %s\n", yytext); }
\+?[0-9]{10,15}                               { printf("Valid Phone Number: %s\n", yytext); }
[0-9]{4}-[0-9]{2}-[0-9]{2}                    { printf("Valid Date (YYYY-MM-DD): %s\n", yytext); }
.                                             { printf("Invalid Pattern: %s\n", yytext); }
\n                                            ;
%%

int main() {
    printf("Enter strings to validate (Email, Phone, Date): \n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
