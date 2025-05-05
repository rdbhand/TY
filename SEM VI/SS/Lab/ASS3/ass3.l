%{
#include "ass3.tab.h"
%}

%%

int     { return DATATYPE; }
float   { return DATATYPE; }
char    { return DATATYPE; }
double  { return DATATYPE; }
[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFIER; }
";"     { return SEMICOLON; }
","     { return COMMA; }
[ \t]+  { /* Ignore whitespace */ }
\n      { return 0; }  // End of input

%%

int yywrap() { return 1; }
