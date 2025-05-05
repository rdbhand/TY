%{
#include<stdio.h>
int lc=0, wc=0, cc=0, sc=0;
%}
%%
[\n] {lc++; cc++;}
[ \t] {cc++; sc++;}
[^ \t\n]+ {wc++; cc+=yyleng;}
. {cc++;}
%%
int main(){
  char f_name[20];
  yyin=fopen("file1.txt","r");
  yylex();
  printf("Number of Lines : %d\n",lc);
  printf("Number of Words : %d\n",wc);
  printf("Number of Characters : %d\n",cc);
  printf("Number of Spaces : %d\n",sc);
  return 0;
}

int yywrap(){
  return 1;
}