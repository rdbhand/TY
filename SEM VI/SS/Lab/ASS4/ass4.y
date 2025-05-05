%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(const char* str);
int yylex();
%}

%token NUMBER NL

%left '+' '-'
%left '*' '/' '%'

%%
ArithmeticExpression: E NL {
    printf("Result = %d\n", $$);
    return 0;
};

E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { 
      if ($3 == 0) {
          printf("\nError: Division by zero\n");
          exit(1);
      }
      $$ = $1 / $3;
   }
 | E '%' E { 
      if ($3 == 0) {
          printf("\nError: Modulus by zero\n");
          exit(1);
      }
      $$ = $1 % $3;
   }
 | '(' E ')' { $$ = $2; }
 | NUMBER { $$ = $1; }
;

%%

int main() {
    printf("Enter an arithmetic expression: \n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("\nError: Invalid arithmetic expression\n\n");
    flag = 1;
}
