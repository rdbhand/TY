%{
#include<stdio.h>
#include<stdlib.h>
#include "ass4.tab.h"
extern int yylval;
%}

%%
[0-9]+     { yylval = atoi(yytext); return NUMBER; }
[ \t]      { /* Ignore spaces and tabs */ }
[\n]       { return NL;}
.          { return yytext[0]; }  /* Return single-character operators */
%%

int yywrap() {
    return 1;
}
