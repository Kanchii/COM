#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TIPO_INT 1
#define TIPO_STRING 2
#define TIPO_FLOAT 3
#define TIPO_ID 4

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
#define OP_ALEA 100

#define MAX_HASH 113
#define MAX_STR_SIZE 11

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
	char id[11];
	int tipo, posicao;
};
typedef struct stuff stuff;

typedef struct STF {
    char id[11];
    int posicao;
} stf;

struct TabSimb {
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
    UnionV value;
	struct ArvSint *ptr1, *ptr2, *ptr3;
};

struct TabSimb tabSimb[MAX_HASH];

struct Atributos {
	int tipo;
    UnionV value;
	LDDE *listaID;
	struct ArvSint *arvSint;
};

/* Lista usada para criar a tabela de simbolos */
LDDE * listaCriar(unsigned long tamInfo);
LDDE * listaInserir(LDDE *p, void *novo, int pos);
int listaBuscaInicio(LDDE *p, void *reg);
int listaBuscaElemento(LDDE *p, void *reg, void *dest);
int listaBuscaFim(LDDE *p, void *reg);
int listaRemover(LDDE * p, NoLDDE * node);
void destroi(LDDE **pp);

int binaryOp(int op);

/* Nodos da arvore sintatica */
struct ArvSint * criaNo(int op, struct ArvSint *ptr1, struct ArvSint *ptr2, struct ArvSint *ptr3);
struct ArvSint * criaNoV(int tipo, UnionV v);
struct ArvSint *createNodoConversor(int op, struct ArvSint *ptr);

/* Percorrer arvore pos ordem */
char *printOperador(int op);
void printPosOrdem(struct ArvSint *no);

/* JVM */
void buildJVM(struct ArvSint *no);
void buildJVMUtil(FILE *f, struct ArvSint *no);

/* Graphviz */
void createGraphviz(struct ArvSint *no);
void createGraphvizMarca(FILE *f, struct ArvSint *no, int *cnt);
void createGraphvizFinaliza(FILE *f, struct ArvSint *no);

/*Tabela*/
int hash(char *id);
void insereTabSimbolo(LDDE *p, int tipo);
void listaInserirTabSimb(LDDE **pp, void *novo);
int consultaTipoTabSimb(char *nome);
int consultaPosiTabSimb(char *nome);
void printTabSimb();

/* Verificacao se um numero eh float */
int ehFloat(char *num);

#endif
