#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <string.h>

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

LDDE * listaCriar(unsigned long tamInfo);
LDDE * listaInserir(LDDE *p, void *novo, int posicao);
int listaBuscaInicio(LDDE *p, void *reg);
int listaBuscaElemento(LDDE *p, void *reg, void *dest);
int listaBuscaFim(LDDE *p, void *reg);
int listaRemover(LDDE * p, NoLDDE * node);
void destroi(LDDE **pp);


int hash(char *id);
void insereTabSimbolo(struct TabSimb *tabSimb, LDDE *p, int tipo);
void listaInserirTabSimb(LDDE **pp, void *novo);
int consultaTipoTabSimb(struct TabSimb *tambSimb, char *nome);

void printTabSimb(struct TabSimb *tabSimb);

#endif
