%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
\/\/.* {printf("SINGLE LINE COMMENT: %s\n",yytext);}
# {printf("PREPROCESSOR DIRECTIVE: %s\n", yytext);}
"<"[a-zA-Z]+".h>" {printf("HEADER FILE : %s\n", yytext);}
"int"|"float"|"return"|"if"|"else"|"while"|"for"|"void"   { printf("KEYWORD: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIER: %s\n", yytext); }
[0-9]+(\.[0-9]+)?    { printf("NUMBER: %s\n", yytext); }
\".*\" {printf("STRING: %s\n", yytext);}
[+\-*/=<>]  { printf("OPERATOR: %s\n", yytext); }
[;,\{\}\(\)] { printf("PUNCTUATION: %s\n", yytext); }
%%

int main() {
    yyin = fopen("input.c", "r");
    yylex();          
    return 0;
}

int yywrap() {
    return 1;
}
