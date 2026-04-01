%{
#include "ambiguity.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }
[ \t]   ; /* skip whitespace */
\n      { return 0; }
.       { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
