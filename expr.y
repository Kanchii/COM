%{
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define YYSTYPE struct Atributos
int linha = 1;
int pos = 1;
%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TMENOR TMAIOR TMENORIG TMAIORIG TIGUAL TDIF
%token TAND TOR TNOT TID TACH TFCH TVOID TINT TSTRING TFLOAT TRETURN TPEV TATRIB TIF TWHILE
%token TELSE TPRINT TREAD TLITERAL TVIR
%%

Linha: Programa {printTabSimb(); printf("\n\n"); buildJVM($1.arvSint); createGraphviz($1.arvSint); printf("\n\n\tSUCESSO\n"); exit(0);}
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

 ListaId: ListaId TVIR TID {$$.listaID = listaInserir($1.listaID, (void *)$3.value.id, pos++);}
        | TID {$$.listaID = listaCriar(sizeof(stf)); $$.listaID = listaInserir($$.listaID, (void *)$1.value.id, pos++);}
        ;

 Bloco: TACH ListaCmd TFCH {$$.arvSint = $2.arvSint;}
 ;

 ListaCmd: ListaCmd Comando {$$.arvSint = criaNo(OP_ALEA, $2.arvSint, $1.arvSint, NULL);}
    | Comando {$$.arvSint = $1.arvSint;}
    ;

 Comando: CmdSe {$$.arvSint = $1.arvSint;}
   | CmdEnquanto {$$.arvSint = $1.arvSint;}
   | CmdAtrib {$$.arvSint = $1.arvSint;}
   | CmdEscrita {$$.arvSint = $1.arvSint;}
   | CmdLeitura {$$.arvSint = $1.arvSint;}
   | ChamadaProc
   | Retorno
   ;

 Retorno: TRETURN ExprAritmetica TPEV {$$.arvSint = criaNo(OP_RETURN, $2.arvSint, NULL, NULL);}
   | TRETURN TLITERAL TPEV {$$.arvSint = criaNo(OP_RETURN, criaNoV(TIPO_STRING, $2.value), NULL, NULL);}
   ;

 CmdSe: TIF TAPAR ExprLogica TFPAR Bloco {$$.arvSint = criaNo(OP_IF, $3.arvSint, $5.arvSint, NULL);}
 | TIF TAPAR ExprLogica TFPAR Bloco TELSE Bloco {$$.arvSint = criaNo(OP_IF, $3.arvSint, $5.arvSint, $7.arvSint);}
 ;

 CmdEnquanto: TWHILE TAPAR ExprLogica TFPAR Bloco {$$.arvSint = criaNo(OP_WHILE, $3.arvSint, $5.arvSint, NULL);}
       ;

 CmdAtrib: TID TATRIB ExprAritmetica TPEV {$$.arvSint = criaNo(OP_ATRIB, criaNoV($1.tipo, $1.value), $3.arvSint, NULL);}
	     | TID TATRIB TLITERAL TPEV {$$.arvSint = criaNo(OP_ATRIB, criaNoV($1.tipo, $1.value), criaNoV(TIPO_STRING, $3.value), NULL);}
	     | TID TATRIB ChamadaProc TPEV
	     ;

 CmdEscrita: TPRINT TAPAR ExprAritmetica TFPAR TPEV {$$.arvSint = criaNo(OP_PRINT, $3.arvSint, NULL, NULL);}
      | TPRINT TAPAR TLITERAL TFPAR TPEV {$$.arvSint = criaNo(OP_PRINT, criaNoV(TIPO_STRING, $3.value), NULL, NULL);}
      ;

 CmdLeitura: TREAD TAPAR TID TFPAR TPEV {$$.arvSint = criaNo(OP_READ, criaNoV(TIPO_ID, $3.value), NULL, NULL);}
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

Fator: TNUM {$$.arvSint = criaNoV($1.tipo, $1.value);}
	 | TID {$$.arvSint = criaNoV($1.tipo, $1.value);}
	 | TAPAR ExprAritmetica TFPAR {$$.arvSint = $2.arvSint;}
	 | TSUB Fator {$$.arvSint = criaNo(OP_SUB, $2.arvSint, NULL, NULL);}
	 ;

ExprRelacional: ExprAritmetica TMENOR ExprAritmetica {$$.arvSint = criaNo(OP_MENOR, $1.arvSint, $3.arvSint, NULL);}
				| ExprAritmetica TMAIOR ExprAritmetica {$$.arvSint = criaNo(OP_MAIOR, $1.arvSint, $3.arvSint, NULL);}
				| ExprAritmetica TMENORIG ExprAritmetica {$$.arvSint = criaNo(OP_MENORIG, $1.arvSint, $3.arvSint, NULL);}
				| ExprAritmetica TMAIORIG ExprAritmetica {$$.arvSint = criaNo(OP_MAIORIG, $1.arvSint, $3.arvSint, NULL);}
				| ExprAritmetica TIGUAL ExprAritmetica {$$.arvSint = criaNo(OP_CMP, $1.arvSint, $3.arvSint, NULL);}
				| ExprAritmetica TDIF ExprAritmetica {$$.arvSint = criaNo(OP_DIF, $1.arvSint, $3.arvSint, NULL);}
				;

ExprLogica: ExprLogica TAND ExprLogicaT2 {$$.arvSint = criaNo(OP_AND, $2.arvSint, NULL, NULL);}
					| ExprLogica TOR ExprLogicaT2 {$$.arvSint = criaNo(OP_OR, $1.arvSint, $3.arvSint, NULL);}
					| ExprLogicaT2 {$$.arvSint = $1.arvSint;}
					;

ExprLogicaT2: TAPAR ExprLogica TFPAR {$$.arvSint = $2.arvSint;}
			| TNOT ExprLogicaT2 {$$.arvSint = criaNo(OP_NOT, $2.arvSint, NULL, NULL);}
			| ExprRelacional {$$.arvSint = $1.arvSint;}
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
