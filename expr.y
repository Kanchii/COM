%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TMENOR TMAIOR TMENORIG TMAIORIG TIGUAL TDIF
%token TAND TOR TNOT TID TACH TFCH TVOID TINT TSTRING TFLOAT TRETURN TPEV TATRIB TIF TWHILE
%token TELSE TPRINT TREAD TLITERAL TVIR
%%

Linha: ExprAritmetica {printf("Resultado: %lf\n", $1);exit(0);}
	 | ExprRelacional {printf("Expressao Relacional\n"); exit(0);}
	 | ExprLogica {printf("Expressao Logica\n"); exit(0);}
	 | CmdAtrib {printf("Atrib\n"); exit(0);}
	 | Programa {printf("Reconheceu, meu consagrado!\n"); exit(0);}
	 ;

 Programa: ListaFuncoes BlocoPrincipal
    | BlocoPrincipal
    ;

 ListaFuncoes: ListaFuncoes Funcao
        | Funcao
        ;

 Funcao: TipoRetorno TID TAPAR DeclParametros TFPAR BlocoPrincipal
	   | TipoRetorno TID TAPAR TFPAR BlocoPrincipal
	   ;

 TipoRetorno: Tipo
       | TVOID
       ;

 DeclParametros: DeclParametros TVIR Parametro
          | Parametro
          ;

 Parametro: Tipo TID
     ;

 BlocoPrincipal: TACH Declaracoes ListaCmd TFCH
          | Bloco
          ;

 Declaracoes: Declaracoes Declaracao
       | Declaracao
       ;

 Declaracao: Tipo ListaId TPEV
           ;

 Tipo: TINT
 | TSTRING
 | TFLOAT
 ;

 ListaId: ListaId TVIR TID
        | TID
        ;

 Bloco: TACH ListaCmd TFCH
 ;

 ListaCmd: ListaCmd Comando
    | Comando
    ;

 Comando: CmdSe
   | CmdEnquanto
   | CmdAtrib
   | CmdEscrita
   | CmdLeitura
   | ChamadaProc
   | Retorno
   ;

 Retorno: TRETURN ExprAritmetica TPEV
   | TRETURN TLITERAL TPEV
   ;

 CmdSe: TIF TAPAR ExprRelacional TFPAR Bloco
 | TIF TAPAR ExprRelacional TFPAR Bloco TELSE Bloco
 ;

 CmdEnquanto: TWHILE TAPAR ExprLogica TFPAR Bloco
       ;

 CmdAtrib: TID TATRIB ExprAritmetica TPEV
    | TID TATRIB TLITERAL TPEV
    | TID TATRIB ExprRelacional TPEV
    | TID TATRIB ExprLogica TPEV
    | TID TATRIB ChamadaProc TPEV
    ;

 CmdEscrita: TPRINT TAPAR ExprAritmetica TFPAR TPEV
      | TPRINT TAPAR TLITERAL TFPAR TPEV
      ;

 CmdLeitura: TREAD TAPAR TID TFPAR TPEV
      ;

 ChamadaProc: ChamadaFuncao
       ;

 ChamadaFuncao: TID TAPAR ListaParametros TFPAR
         | TID TAPAR TFPAR
         ;

 ListaParametros: ListaParametros TVIR ExprAritmetica
           | ListaParametros TVIR TLITERAL
           | ExprAritmetica
           | TLITERAL
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
	 | TID
	 | TAPAR ExprAritmetica TFPAR {$$ = $2;}
	 ;

 ExprRelacional: ExprRelacionalT2 TMENOR ExprAritmetica
 		      | ExprRelacionalT2 TMAIOR ExprAritmetica
 			  | ExprRelacionalT2 TMENORIG ExprAritmetica
 		      | ExprRelacionalT2 TMAIORIG ExprAritmetica
 			  | ExprRelacionalT2 TIGUAL ExprAritmetica
 			  | ExprRelacionalT2 TDIF ExprAritmetica
			  | ExprRelacionalT2
 			  ;
ExprRelacionalT2: TAPAR ExprRelacional TFPAR
				| ExprAritmetica
				;

 ExprLogica: ExprLogica TAND ExprLogicaT2
 		  | ExprLogica TOR ExprLogicaT2
 		  | ExprLogicaT2
 		  ;

 ExprLogicaT2: TAPAR ExprLogica TFPAR
 			| TNOT ExprLogica
 			| ExprRelacional
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
