#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TIPO_VOID 0
#define TIPO_INT 1
#define TIPO_STRING 2
#define TIPO_FLOAT 3
#define TIPO_ID 4
#define TIPO_IDFUNCAO 5

#define OP_ADD 1
#define OP_SUB 2
#define OP_MULT 3
#define OP_DIV 4
#define OP_INTTOFLOAT 5
#define OP_PRINT 6
#define OP_ATRIB 7
#define OP_RETURN 8
#define OP_READ 9
#define OP_IF 10
#define OP_MENOR 11
#define OP_MENORIG 12
#define OP_MAIOR 13
#define OP_MAIORIG 14
#define OP_DIF 15
#define OP_CMP 16
#define OP_AND 17
#define OP_OR 18
#define OP_NOT 19
#define OP_WHILE 20
#define OP_FLOATTOINT 21
#define OP_FOR 22
#define OP_FUNC 23
#define OP_RAIZ 24
#define OP_PARAMETROS 25
#define OP_CHAMFUNC 26
#define OP_ALEA 100

#define MAX_HASH 113
#define MAX_STR_SIZE 50

extern int label;

typedef struct noLDDE {
    void *dados;
    struct noLDDE *prox;
    struct noLDDE *ant;
} NoLDDE;

typedef struct LDDE {
    unsigned long tamInfo;
    NoLDDE *inicioLista;
    NoLDDE *fimLista;
} LDDE;

struct stuff {
	char id[MAX_STR_SIZE];
	int tipo, posicao;
};
typedef struct stuff stuff;

typedef struct STF {
    char id[MAX_STR_SIZE];
    int posicao;
} stf;

typedef struct Desespero {
    int value;
} Desespero;

struct TabSimb {
	LDDE * lista;
};

typedef struct DadosTabFunc {
    char * nome;
    int tipoRetorno;
    LDDE * listaArgs;
} dadosTabFunc;

struct TabSimbF {
    LDDE * lista;
};

typedef union V {
    float floatV;
    int intV;
    char *stringV;
	char id[MAX_STR_SIZE];
} UnionV;

struct ArvSint {
	int op;
    int tipo;
    int graphID;
    int posicaoFuncao;
    int tipoFuncao;
    char nomeFuncao[MAX_STR_SIZE];
    UnionV value;
	struct ArvSint *ptr1, *ptr2, *ptr3, *ptr4;
};

struct TabSimb tabSimb[MAX_HASH];
struct TabSimb tabSimbTmp[MAX_HASH];
struct TabSimbF tabFunc[MAX_HASH];

struct Atributos {
	int tipo;
    UnionV value;
    int posicaoFuncao;
    int tipoFuncao;
    char nomeFuncao[MAX_STR_SIZE];
    LDDE *listaTipos;
	LDDE *listaID;
	struct ArvSint *arvSint;
};

/* Lista usada para criar a tabela de simbolos */
LDDE * listaCriar(unsigned long tamInfo);
LDDE * listaInserir(LDDE *p, void *novo, int pos);
LDDE * listaInserir2(LDDE *p, void * novo);
int listaBuscaInicio(LDDE *p, void *reg);
int listaBuscaElemento(LDDE *p, void *reg, void *dest);
int listaBuscaFim(LDDE *p, void *reg);
int listaRemover(LDDE * p, NoLDDE * node);
void destroi(LDDE **pp);

int binaryOp(int op);

/* Nodos da arvore sintatica */
struct ArvSint * criaNo(int op, struct ArvSint *ptr1, struct ArvSint *ptr2, struct ArvSint *ptr3);
struct ArvSint * cria4No(int op, struct ArvSint *ptr1, struct ArvSint *ptr2, struct ArvSint *ptr3, struct ArvSint *ptr4);
struct ArvSint * criaNoV(int tipo, UnionV v);
struct ArvSint *createNodoConversor(int op, struct ArvSint *ptr);
struct ArvSint *criaConstNum(int tipo, float value);
void printParametros(FILE *f, struct ArvSint *no);

/* Percorrer arvore pos ordem */
char *printOperador(int op);
void printPosOrdem(struct ArvSint *no);

/* JVM */
void printInit(FILE *f);
void printInitMain(FILE *f);
void printEnd(FILE *f);
void buildJVM(struct ArvSint *no);
void buildJVMFunctions(FILE *f, struct ArvSint *no);
void buildJVMUtil(FILE *f, struct ArvSint *no);
void buildJVMPost(FILE *f, struct ArvSint *no);
void gerarExprLogRel(FILE *f, struct ArvSint *no, int lv, int lf);

/* Graphviz */
void createGraphviz(struct ArvSint *no);
void createGraphvizMarca(FILE *f, struct ArvSint *no, int *cnt, int inFunction);
void createGraphvizFinaliza(FILE *f, struct ArvSint *no);

/*Tabela Simbolos*/
int hash(char *id);
void insereTabSimbolo(LDDE *p, int tipo);
void listaInserirTabSimb(LDDE **pp, void *novo);
int consultaTipoTabSimb(char *nome);
int consultaPosiTabSimb(char *nome);
void printTabSimb();

/*Tabela Funcao*/
void insereTabFuncao(int tipo, char *nome, LDDE * lista);
void insereTabSimboloTmp(LDDE *p, int tipo);
int consultaPosiTabSimbFunc(char *nome);
int consultaTipoTabSimbFunc(char *nome);
LDDE * consultaTipoArgsTabFunc(char *nome);
int consultaTipoRetornoTabFunc(char *nome);
void printTabSimbTmp();
void clearTabSimbTmp();
void printTipoArgsFunc(FILE *f, char *nome);
void printTipoRetornoFunc(FILE *f, char *nome);

void printTabFunc();

/* Verificacao se um numero eh float */
int ehFloat(char *num);
void reverse(char s[]);
void itoa(int n, char s[]);
#endif
