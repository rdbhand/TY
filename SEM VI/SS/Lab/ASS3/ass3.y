%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char* str);
int yylex();
%}

%token DATATYPE IDENTIFIER SEMICOLON COMMA
%start s

%%

s: DATATYPE var_list SEMICOLON { printf("Valid Declaration ...............\n"); }
 ;

var_list: IDENTIFIER 
        | var_list COMMA IDENTIFIER
 ;

%%

void yyerror(const char* str) {
    printf("Invalid Declaration !!\n");
}

int main() {
    printf("Declare A Variable: ");
    yyparse();
    return 0;
}
