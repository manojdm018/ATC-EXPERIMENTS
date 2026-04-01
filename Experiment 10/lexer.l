%{
#include "code_gen.tab.h"
#include <string.h>
%}

%%
[0-9]+          { strcpy(yylval.name, yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { strcpy(yylval.name, yytext); return ID; }
[ \t]           ; /* skip whitespace */
\n              { return 0; }
.               { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
