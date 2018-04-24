%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TFIM TMENOR TMAIOR TMENORIG TMAIORIG TIGUAL TDIF
%token TAND TOR TNOT TID TACH TFCH TVOID TINT TSTRING TFLOAT TRETURN TPEV TATRIB TIF TWHILE
%token TELSE TPRINT TREAD TLITERAL
%%
Linha: ExprAritmetica TFIM {printf("Resultado: %lf\n", $1);exit(0);}
	 | ExprRelacional TFIM {printf("Expressao Relacional\n"); exit(0);}
	 | ExprLogica TFIM {printf("Expressao Logica\n"); exit(0);}
	 | CmdLeitura TFIM {printf("Leu tudo certinho!\n"); exit(0);}
	 | DeclaraVariavel {printf("Voce declarou uma variavel!\n"); exit(0);}
	 ;

CmdLeitura: TREAD TAPAR TID TFPAR TPEV
			;

Tipo: TINT
	| TSTRING
	| TFLOAT

DeclaraVariavel: Tipo TID TPEV
						| Tipo TID TATRIB TLITERAL TPEV

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
					| ExprRelacionalT2
				  ;
ExprRelacionalT2: TAPAR ExprRelacional TFPAR

ExprLogica: ExprRelacional TAND ExprRelacional
			| ExprRelacional TAND ExprLogica
			| ExprRelacional TAND ExprAritmetica
		  | ExprRelacional TOR ExprRelacional
			| ExprRelacional TOR ExprLogica
			| ExprRelacional TOR ExprAritmetica
			| ExprAritmetica TOR ExprRelacional
			| ExprAritmetica TOR ExprLogica
			| ExprAritmetica TOR ExprAritmetica
		  | ExprAritmetica TAND ExprLogica
			| ExprAritmetica TAND ExprRelacional
			| ExprAritmetica TAND ExprAritmetica
		  | ExprLogicaT2
		  ;
ExprLogicaT2: TAPAR ExprLogica TFPAR
			| TNOT ExprLogica
			| TNOT ExprRelacional
			| TNOT ExprAritmetica
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
