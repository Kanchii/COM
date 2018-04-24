%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TFIM TMENOR TMAIOR TMENORIG TMAIORIG TIGUAL TDIF
%token TAND TOR TNOT

%%
Linha: ExprAritmetica TFIM {printf("Resultado: %lf\n", $1);exit(0);}
	 | ExprRelacional TFIM {printf("Expressao Relacional\n"); exit(0);}
	 | ExprLogica TFIM {printf("Expressao Logica\n"); exit(0);}
	 ;
ExprAritmetica: ExprAritmetica TADD Termo {$$ = $1 + $3;}
	          | ExprAritmetica TSUB Termo {$$ = $1 - $3;}
	 	  	  | Termo
			  ;
Termo: Termo TMUL Fator {$$ = $1 * $3;}
	 | Termo TDIV Fator {$$ = $1 / $3;}
	 | Fator
	 ;
Fator: TNUM
	 | TAPAR ExprAritmetica TFPAR {$$ = $2;}
	 ;

ExprRelacional: ExprAritmetica TMENOR ExprAritmetica
		      | ExprAritmetica TMAIOR ExprAritmetica
			  | ExprAritmetica TMENORIG ExprAritmetica
			  | ExprAritmetica TMAIORIG ExprAritmetica
			  | ExprAritmetica TIGUAL ExprAritmetica
			  | ExprAritmetica TDIF ExprAritmetica
			  | TAPAR ExprRelacional TFPAR
			  ;
ExprLogica: ExprRelacional TAND ExprRelacional
		  | ExprRelacional TOR ExprRelacional
		  | ExprRelacional TAND ExprLogica
		  | ExprRelacional TOR ExprLogica
		  | ExprLogicaT2
		  ;
ExprLogicaT2: TAPAR ExprLogica TFPAR
			| TNOT ExprLogica
			| TNOT ExprRelacional
			;

%%
#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s\n", str, yytext);

}

int yywrap()
{
	return 1;
}
