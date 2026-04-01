%{
#include "control_flow.tab.h"
%}

%%
"if"    { return IF; }
"else"  { return ELSE; }
"while" { return WHILE; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }
[0-9]+  { return NUM; }
"=="|"!="|"<="|">="|"<"|">" { return RELOP; }
[ \t\n] ; /* skip whitespace */
.       { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
