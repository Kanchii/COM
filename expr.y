%{
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define YYSTYPE struct Atributos
int linha = 1;
int posicao = 0;

#define TIPO_INT 1
#define TIPO_STRING 2
#define TIPO_FLOAT 3

#define MAX_HASH 113
#define MAX_STR_SIZE 11

struct TabSimb tabSimb[MAX_HASH];

struct ArvSint {
	int op, valor;
	char id[11];
	struct ArvSint *prt1, *prt2, *prt3;
};

struct Atributos {
	int tipo;
	int valorInt;
	float valorFloat;
	LDDE *listaID;
	char id[MAX_STR_SIZE];
	struct ArvSint *arvSint;
};

%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TMENOR TMAIOR TMENORIG TMAIORIG TIGUAL TDIF
%token TAND TOR TNOT TID TACH TFCH TVOID TINT TSTRING TFLOAT TRETURN TPEV TATRIB TIF TWHILE
%token TELSE TPRINT TREAD TLITERAL TVIR
%%

Linha: Programa {printTabSimb(tabSimb); printf("\n\n\tSUCESSO\n"); exit(0);}
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
          | TACH ListaCmd TFCH
          ;

 Declaracoes: Declaracoes Declaracao
       | Declaracao
       ;

 Declaracao: Tipo ListaId TPEV {insereTabSimbolo(tabSimb, $2.listaID, $1.tipo);}
           ;

 Tipo: TINT {$$.tipo = TIPO_INT;}
 | TSTRING {$$.tipo = TIPO_STRING;}
 | TFLOAT {$$.tipo = TIPO_FLOAT;}
 ;

 ListaId: ListaId TVIR TID {$$.listaID = listaInserir($1.listaID, (void *)$3.id, posicao);}
        | TID {$$.listaID = listaCriar(sizeof(stf)); $$.listaID = listaInserir($$.listaID, (void *)$1.id, posicao);}
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

 CmdSe: TIF TAPAR ExprLogica TFPAR Bloco
 | TIF TAPAR ExprLogica TFPAR Bloco TELSE Bloco
 ;

 CmdEnquanto: TWHILE TAPAR ExprLogica TFPAR Bloco
       ;

 CmdAtrib: TID TATRIB ExprAritmetica TPEV
    | TID TATRIB TLITERAL TPEV
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

ExprAritmetica: ExprAritmetica TADD Termo
		          | ExprAritmetica TSUB Termo
		 	  	  	| Termo
				  		;

Termo: Termo TMUL Fator
	 | Termo TDIV Fator
	 | Fator
	 ;

Fator: TNUM
	 | TID
	 | TAPAR ExprAritmetica TFPAR
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
