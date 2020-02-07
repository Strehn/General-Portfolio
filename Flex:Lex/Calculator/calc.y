%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sym.h"

%}

%{ int sym_count = 2;
   %}

%union {
  double dval;
  struct sym * symptr;
}

%token <symptr> NAME
%token <dval> NUMBER
%token <symptr> PI 
%token <symptr> PHI
%token <symptr> PRINT

%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%type <dval> expression
%type <dval> constant
%%

statement_list
 : statement '\n'
 | statement_list statement '\n'
 ;

constant
 : PI {$1->value = 3.14159; $$ = 3.14159; }
 | PHI {$1->value = 1.61803; $$ = 1.61803; }
 ; 

statement
 : NAME '=' expression { $1->value = $3; }
 | constant '=' expression { printf("assign to constant \n = %g \n", $1); }
 | expression { printf("= %g\n", $1); }
 | PRINT {printf("num-syms: %d\n", sym_count);
          struct sym * sp;
          for( sp = head; sp != NULL; sp = sp->next)
              {
		printf("\t%s => %f\n", sp->name, sp->value);
               }
         }
;

expression
 : expression '+' expression { $$ = $1 + $3; }
 | expression '-' expression { $$ = $1 - $3; }
 | expression '*' expression { $$ = $1 * $3; }
 | expression '/' expression { 
  if($3)                           
    $$ = $1 / $3;                        
  else{
    printf("divide by zero\n");
  $$ = $1;
  } }
 | '-' expression %prec UMINUS { $$ = -$2; }
 | '(' expression ')' { $$ = $2; }
 | constant
 | NUMBER 
 | NAME { $$ = $1->value; }
 ;

%%

int main( ){
  sym_constants( );
  yyparse( );
  return 0;
}

struct sym * sym_lookup(char * s, double x)
{
  char * p;
  struct sym * sp = malloc(sizeof(struct sym));
  struct sym * temp;
  struct sym * prev = malloc(sizeof(struct sym));

  for( sp = head; sp != NULL; sp = sp->next)
    {
      if (sp->name && strcmp(sp->name, s) == 0)
	return sp;

  //ASKI ORDER
  if (strcmp(s, sp->name) < 0)
    {
      struct sym * temp = malloc(sizeof(struct sym));
      prev->next = temp;
      temp->name = strdup(s);
      temp->next = sp;
      sym_count++;
      return temp;
    }
  else if( sp->next == NULL)
    {
      sp->next = malloc(sizeof(struct sym));
      sp->next->name = strdup(s);
      sym_count++;
      return sp->next;
    }
  else
    {
      prev = sp;
      continue;
    }
 }
  return NULL; /* unreachable */
}
  
void sym_constants( )
{
  struct sym * node = malloc(sizeof(struct sym));
  
  node->name = "PHI";
  node->value = 1.61803;
  node->next = malloc(sizeof(struct sym));
  node->next->name = "PI";
  node->next->value = 3.14159;
  node->next->next = NULL;

  head = node;
}
