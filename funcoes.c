#include "funcoes.h"
#include <stdio.h>

//Criar lista
LDDE * listaCriar(unsigned long tamInfo) {
    LDDE *desc = (LDDE*) malloc(sizeof(LDDE));

    if(!desc) {
        exit(EXIT_FAILURE);
    } else {
        desc->inicioLista = NULL;
        desc->fimLista    = NULL;
        desc->tamInfo     = tamInfo;
    }

    return desc;
}

LDDE * listaInserir(LDDE *p, void *novo) {
    if(p == NULL){
        p = listaCriar(sizeof(novo));
    }

    NoLDDE *temp;

    if((temp = (NoLDDE*) malloc(sizeof(NoLDDE))) != NULL) {
        if((temp->dados = (void*) malloc(p->tamInfo)) != NULL) {
            memcpy(temp->dados, novo, p->tamInfo);
            temp->prox = NULL;
            if(p->inicioLista == NULL && p->fimLista == NULL) {
                temp->ant = NULL;
                p->fimLista    = temp;
                p->inicioLista = temp;
            } else if(p->inicioLista == p->fimLista) {
                temp->ant  = p->inicioLista;
                temp->prox = NULL;
                p->fimLista = temp;
                p->inicioLista->prox = p->fimLista;
            } else {
                temp->ant   = p->fimLista;
                temp->prox  = NULL;
                p->fimLista->prox = temp;
                p->fimLista = temp;
            }
        }
        else{
            free(temp);
        }
    }
    return p;
}

int listaBuscaInicio(LDDE *p, void *reg) {
    int ret = 0;
    if(p->inicioLista != NULL) {
        memcpy(reg, p->inicioLista->dados, p->tamInfo);
        ret = 1;
    }
    return ret;
}

int listaBuscaFim(LDDE *p, void *reg) {
    int ret = 0;
    if(p->fimLista != NULL) {
        memcpy(reg, p->fimLista->dados, p->tamInfo);
        ret = 1;
    }
    return ret;
}

int listaRemover(LDDE * p, NoLDDE * node) {
    if(p->inicioLista == p->fimLista && p->inicioLista != NULL){ // Lista com 1 elemento
        if(p->inicioLista == node) { // node para excluir = node inicio lista
            free(p->inicioLista);
            p->inicioLista = NULL;
            p->fimLista    = NULL;
            return 1;
        }
        return 0;
    } else{ // lista com mais de 1 elemento
        NoLDDE * aux;
        if(p->inicioLista == node) { //node para excluir  = node inicio lista
            aux = p->inicioLista;
            p->inicioLista = p->inicioLista->prox;
            p->inicioLista->ant = NULL;
            free(aux);
            return 1;
        } else if(p->fimLista == node) { // node para excluir = node fim lista
            aux = p->fimLista;
            p->fimLista = p->fimLista->ant;
            p->fimLista->prox = NULL;
            free(aux);
            return 1;
        } else { // lista com mais de 2 elementos, e node para excluir != node fim lista e node inicio lista
            NoLDDE * temp = p->inicioLista;
            while(temp != NULL) {
                if(temp == node) {
                    aux = node;
                    node->prox->ant = node->ant;
                    node->ant->prox = node->prox;
                    free(aux);
                    return 1;
                }
                temp = temp->prox;
            }
        }
    }

    return 0;
}

void destroi(LDDE **pp) {
    free(*pp);
    (*pp) = NULL;
}

int hash(char *id){
    int n, i;
    int MAX_HASH = 509;
	int hash = n = strlen(id);
	for (i = 0; i < n; i++) {
		hash = (hash * (id[i] + i) ^ 843273) % MAX_HASH;
		if (hash < 0) hash = -hash;
	}
	return hash;
}

void insereTabSimbolo(struct TabSimb *tabSimb, LDDE *p, int tipo){
    NoLDDE * no = p -> inicioLista;
    while(no != NULL) {
        char tmp[11];
        strcpy(tmp, (char *)no->dados);
        int h = hash(tmp);

        stuff *_tmp = (stuff *)malloc(sizeof(stuff));

        strcpy(_tmp->id, tmp);
        _tmp->tipo = tipo;

        listaInserirTabSimb(&(tabSimb[h].lista), (void *)_tmp);

        no = no->prox;
    }
}

void listaInserirTabSimb(LDDE **pp, void *novo){
    if(*pp == NULL){
        *pp = listaCriar(sizeof(stuff));
    }
    NoLDDE *temp;

    if((temp = (NoLDDE*) malloc(sizeof(NoLDDE))) != NULL) {
        if((temp->dados = (void*) malloc((*pp)->tamInfo)) != NULL) {
            memcpy(temp->dados, novo, (*pp)->tamInfo);
            temp->prox = NULL;
            if((*pp)->inicioLista == NULL && (*pp)->fimLista == NULL) {
                temp->ant = NULL;
                (*pp)->fimLista    = temp;
                (*pp)->inicioLista = temp;
            } else if((*pp)->inicioLista == (*pp)->fimLista) {
                temp->ant  = (*pp)->inicioLista;
                temp->prox = NULL;
                (*pp)->fimLista = temp;
                (*pp)->inicioLista->prox = (*pp)->fimLista;
            } else {
                temp->ant   = (*pp)->fimLista;
                temp->prox  = NULL;
                (*pp)->fimLista->prox = temp;
                (*pp)->fimLista = temp;
            }
        }
        else{
            free(temp);
        }
    }
}

void printTabSimb(struct TabSimb *tabSimb){
    int i = 0;
    printf("%-10s%9s%20s\n", "ID", "Tipo", "Posicao");
    for(i = 0; i < 509; i++) {
        if(tabSimb[i].lista != NULL) {
            NoLDDE * no = tabSimb[i].lista -> inicioLista;
            while(no != NULL) {
                stuff *aux = (stuff *)no->dados;
                printf("%-15s%-15s%10s\n", aux -> id, (aux -> tipo == 1 ? "INT" : (aux -> tipo == 2 ? "STRING" : "FLOAT")), "----------");
                no = no->prox;
            }
        }
    }
}