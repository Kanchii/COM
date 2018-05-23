%{
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define YYSTYPE struct Atributos
int linha = 1;

%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TMENOR TMAIOR TMENORIG TMAIORIG TIGUAL TDIF
%token TAND TOR TNOT TID TACH TFCH TVOID TINT TSTRING TFLOAT TRETURN TPEV TATRIB TIF TWHILE
%token TELSE TPRINT TREAD TLITERAL TVIR
%%

Linha: Programa {printTabSimb(); printPosOrdem($1.arvSint); printf("\n\n\tSUCESSO\n"); exit(0);}
	 ;

 Programa: ListaFuncoes BlocoPrincipal {$$.arvSint = $2.arvSint;}
    | BlocoPrincipal {$$.arvSint = $1.arvSint;}
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

 BlocoPrincipal: TACH Declaracoes ListaCmd TFCH {$$.arvSint = $3.arvSint;}
          | TACH ListaCmd TFCH {$$.arvSint = $2.arvSint;}
          ;

 Declaracoes: Declaracoes Declaracao
       | Declaracao
       ;

 Declaracao: Tipo ListaId TPEV {insereTabSimbolo($2.listaID, $1.tipo);}
           ;

 Tipo: TINT {$$.tipo = TIPO_INT;}
 | TSTRING {$$.tipo = TIPO_STRING;}
 | TFLOAT {$$.tipo = TIPO_FLOAT;}
 ;

 ListaId: ListaId TVIR TID {$$.listaID = listaInserir($1.listaID, (void *)$3.id);}
        | TID {$$.listaID = listaCriar(sizeof(stf)); $$.listaID = listaInserir($$.listaID, (void *)$1.id);}
        ;

 Bloco: TACH ListaCmd TFCH {$$.arvSint = $2.arvSint;}
 ;

 ListaCmd: ListaCmd Comando {$$.arvSint = criaNo(OP_ALEA, $1.arvSint, $2.arvSint, NULL);}
    | Comando {$$.arvSint = $1.arvSint;}
    ;

 Comando: CmdSe
   | CmdEnquanto
   | CmdAtrib
   | CmdEscrita {$$.arvSint = $1.arvSint;}
   | CmdLeitura
   | ChamadaProc
   | Retorno
   ;

 Retorno: TRETURN ExprAritmetica TPEV
   | TRETURN TLITERAL TPEV
   ;

 CmdSe: TIF TAPAR ExprLogica TFPAR Bloco
 | TIF TAPAR ExprLogica TFPAR Bloco TELSE Bloco
 ;

 CmdEnquanto: TWHILE TAPAR ExprLogica TFPAR Bloco
       ;

 CmdAtrib: TID TATRIB ExprAritmetica TPEV
    | TID TATRIB TLITERAL TPEV
    | TID TATRIB ChamadaProc TPEV
    ;

 CmdEscrita: TPRINT TAPAR ExprAritmetica TFPAR TPEV {$$.arvSint = $3.arvSint;}
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

ExprAritmetica: ExprAritmetica TADD Termo {$$.arvSint = criaNo(OP_ADD, $1.arvSint, $3.arvSint, NULL);}
		      | ExprAritmetica TSUB Termo {$$.arvSint = criaNo(OP_SUB, $1.arvSint, $3.arvSint, NULL);}
		 	  | Termo {$$.arvSint = $1.arvSint;}
			  ;

Termo: Termo TMUL Fator {$$.arvSint = criaNo(OP_MULT, $1.arvSint, $3.arvSint, NULL);}
	 | Termo TDIV Fator {$$.arvSint = criaNo(OP_DIV, $1.arvSint, $3.arvSint, NULL);}
	 | Fator {$$.arvSint = $1.arvSint;}
	 ;

Fator: TNUM {$$.arvSint = criaNoV($1.id);}
	 | TID {$$.arvSint = criaNoV($1.id);}
	 | TAPAR ExprAritmetica TFPAR {$$.arvSint = $2.arvSint;}
	 | TSUB Fator
	 ;

ExprRelacional: ExprAritmetica TMENOR ExprAritmetica
							| ExprAritmetica TMAIOR ExprAritmetica
							| ExprAritmetica TMENORIG ExprAritmetica
							| ExprAritmetica TMAIORIG ExprAritmetica
							| ExprAritmetica TIGUAL ExprAritmetica
							| ExprAritmetica TDIF ExprAritmetica
							;

ExprLogica: ExprLogica TAND ExprLogicaT2
					| ExprLogica TOR ExprLogicaT2
					| ExprLogicaT2
					;

ExprLogicaT2: TAPAR ExprLogica TFPAR
						| TNOT ExprLogicaT2
						| ExprRelacional
						;

%%
#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s na linha %d\nFRACASSO\n", str, yytext, linha);

}

int yywrap()
{
	return 1;
}
