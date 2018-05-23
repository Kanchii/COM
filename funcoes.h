#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <string.h>

#define TIPO_INT 1
#define TIPO_STRING 2
#define TIPO_FLOAT 3

#define OP_ADD 1
#define OP_SUB 2
#define OP_MULT 3
#define OP_DIV 4
#define OP_ALEA 5

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

struct ArvSint {
	int op;
	char valor[20];
	struct ArvSint *ptr1, *ptr2, *ptr3;
};

struct TabSimb tabSimb[MAX_HASH];

struct Atributos {
	int tipo;
	LDDE *listaID;
	char id[MAX_STR_SIZE];
	struct ArvSint *arvSint;
};

LDDE * listaCriar(unsigned long tamInfo);
LDDE * listaInserir(LDDE *p, void *novo);
int listaBuscaInicio(LDDE *p, void *reg);
int listaBuscaElemento(LDDE *p, void *reg, void *dest);
int listaBuscaFim(LDDE *p, void *reg);
int listaRemover(LDDE * p, NoLDDE * node);
void destroi(LDDE **pp);

struct ArvSint * criaNo(int op, struct ArvSint *ptr1, struct ArvSint *ptr2, struct ArvSint *ptr3);
struct ArvSint * criaNoV(char *valor);

void printPosOrdem(struct ArvSint *no);

int hash(char *id);
void insereTabSimbolo(LDDE *p, int tipo);
void listaInserirTabSimb(LDDE **pp, void *novo);
int consultaTipoTabSimb(char *nome);

void printTabSimb();

#endif
