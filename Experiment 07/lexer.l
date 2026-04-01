%{
#include "ast.tab.h"
#include <string.h>
%}

%%
[0-9]+          { strcpy(yylval.s, yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { strcpy(yylval.s, yytext); return ID; }
[ \t]           ; /* skip whitespace */
\n              { return 0; }
.               { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
