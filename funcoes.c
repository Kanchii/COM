#include "funcoes.h"

#define MAX_HASH 113

int label = 1;

//Lista
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
LDDE * listaInserir(LDDE *p, void *novo, int pos) {
    if(p == NULL){
        p = listaCriar(sizeof(novo));
    }

    NoLDDE *temp;

    if((temp = (NoLDDE*) malloc(sizeof(NoLDDE))) != NULL) {
        if((temp->dados = (void*) malloc(p->tamInfo)) != NULL) {
            stf *tmp  = (stf *)malloc(sizeof(stf));
            strncpy(tmp -> id, novo, 10);
            tmp -> posicao = pos;
            memcpy(temp->dados, tmp, p->tamInfo);
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

/* Arvore */
struct ArvSint *createNodoConversor(int op, struct ArvSint *ptr){
    struct ArvSint *novoNodo = (struct ArvSint *)malloc(sizeof(struct ArvSint));
    novoNodo -> op = op;
    novoNodo -> tipo = (op == OP_INTTOFLOAT ? TIPO_FLOAT : TIPO_INT);
    novoNodo -> ptr1 = ptr;
    novoNodo -> ptr2 = NULL;
    novoNodo -> ptr3 = NULL;
    return novoNodo;
}
int binaryOp(int op){
    return (op == OP_SUB || op == OP_DIV || op == OP_MULT || op == OP_ADD || op == OP_ATRIB);
}
struct ArvSint * criaNo(int op, struct ArvSint *ptr1, struct ArvSint *ptr2, struct ArvSint *ptr3){
    struct ArvSint *tmp = (struct ArvSint *)malloc(sizeof(struct ArvSint));
    tmp -> op = op;

    if(op == OP_ATRIB){
        int t1 = (ptr1 -> tipo == TIPO_ID ? consultaTipoTabSimb(ptr1 -> value.id) : ptr1 -> tipo);
        int t2 = (ptr2 -> tipo == TIPO_ID ? consultaTipoTabSimb(ptr2 -> value.id) : ptr2 -> tipo);
        if(t1 == TIPO_FLOAT && t2 == TIPO_INT){
            ptr2 = createNodoConversor(OP_INTTOFLOAT, ptr2);
        } else if(t1 == TIPO_INT && t2 == TIPO_FLOAT){
            ptr2 = createNodoConversor(OP_FLOATTOINT, ptr2);
        }
    } else if(ptr1 != NULL && ptr2 != NULL && binaryOp(op)){
        int t1 = (ptr1 -> tipo == TIPO_ID ? consultaTipoTabSimb(ptr1 -> value.id) : ptr1 -> tipo);
        int t2 = (ptr2 -> tipo == TIPO_ID ? consultaTipoTabSimb(ptr2 -> value.id) : ptr2 -> tipo);

        if((t1 == TIPO_INT && t2 == TIPO_FLOAT) || (t1 == TIPO_FLOAT && t2 == TIPO_INT)){
            if(t1 == TIPO_INT){
                ptr1 = createNodoConversor(OP_INTTOFLOAT, ptr1);
            } else {
                ptr2 = createNodoConversor(OP_INTTOFLOAT, ptr2);
            }
        }
    }
    if(ptr1 != NULL){
		if(ptr2 != NULL){
			int t1 = (ptr1 -> tipo == TIPO_ID ? consultaTipoTabSimb(ptr1 -> value.id) : ptr1 -> tipo);
			int t2 = (ptr2 -> tipo == TIPO_ID ? consultaTipoTabSimb(ptr2 -> value.id) : ptr2 -> tipo);
			if(t1 != t2){
				tmp -> tipo = TIPO_FLOAT;
			} else {
				tmp -> tipo = t1;
			}
		} else {
			tmp -> tipo = (ptr1 -> tipo == TIPO_ID ? consultaTipoTabSimb(ptr1 -> value.id) : ptr1 -> tipo);
		}
    } else {
        tmp -> tipo = OP_ALEA;
    }
    tmp -> ptr1 = ptr1;
    tmp -> ptr2 = ptr2;
    tmp -> ptr3 = ptr3;
    return tmp;
}
struct ArvSint * cria4No(int op, struct ArvSint *ptr1, struct ArvSint *ptr2, struct ArvSint *ptr3, struct ArvSint *ptr4){
	struct ArvSint *tmp = (struct ArvSint *)malloc(sizeof(struct ArvSint));
    tmp -> op = op;
    tmp -> ptr1 = ptr1;
    tmp -> ptr2 = ptr2;
    tmp -> ptr3 = ptr3;
    tmp -> ptr4 = ptr4;
    return tmp;
}
struct ArvSint * criaNoV(int tipo, UnionV v){
    struct ArvSint *tmp = (struct ArvSint *)malloc(sizeof(struct ArvSint));
    tmp -> ptr1 = NULL;
    tmp -> ptr2 = NULL;
    tmp -> ptr3 = NULL;
    tmp -> op = -1;
    tmp -> tipo = tipo;
    tmp -> value = v;
    return tmp;
}
struct ArvSint *criaConstNum(int tipo, float value){
	struct ArvSint *tmp = (struct ArvSint *)malloc(sizeof(struct ArvSint));
	tmp -> ptr1 = NULL;
    tmp -> ptr2 = NULL;
    tmp -> ptr3 = NULL;
    tmp -> op = -1;
    tmp -> tipo = tipo;
    UnionV v;
    if(tipo == TIPO_INT){
		v.intV = (int)value;
	} else if(tipo == TIPO_FLOAT){
		v.floatV = value;
	}
    tmp -> value = v;
    return tmp;
}

/* Printa em pos ordem*/
char *printOperador(int op){
    switch (op) {
        case OP_ADD:
            return "ADD";
        case OP_SUB:
            return "SUB";
        case OP_DIV:
            return "DIV";
        case OP_MULT:
            return "MULT";
        case OP_INTTOFLOAT:
            return "INTTOFLOAT";
        case OP_FLOATTOINT:
            return "FLOATTOINT";
        case OP_ATRIB:
            return "ATRIB";
        case OP_PRINT:
            return "PRINT";
        case OP_RETURN:
            return "RETURN";
        case OP_READ:
            return "READ";
        case OP_IF:
            return "IF";
        case OP_MENOR:
            return "<";
        case OP_MENORIG:
            return "<=";
        case OP_MAIOR:
            return ">";
        case OP_MAIORIG:
            return ">=";
        case OP_DIF:
            return "!=";
        case OP_AND:
            return "&&";
        case OP_CMP:
			return "==";
        case OP_OR:
            return "||";
        case OP_NOT:
            return "!";
        case OP_WHILE:
            return "WHILE";
        case OP_FOR:
			return "FOR";
        default:
            return "?";
    }
}
void printPosOrdem(struct ArvSint *no){
    if(no == NULL) {
        return;
    }
    printPosOrdem(no -> ptr1);
    printPosOrdem(no -> ptr2);
    printPosOrdem(no -> ptr3);
    printPosOrdem(no -> ptr4);
    if(no -> op == -1){
        if(no -> tipo == TIPO_INT){
            printf("%d -> ", no -> value.intV);
        } else if(no -> tipo == TIPO_FLOAT){
            printf("%.2f -> ", no -> value.floatV);
        } else if(no -> tipo == TIPO_ID){
            printf("%s -> ", no -> value.id);
        } else {
            printf("%s -> ", no -> value.stringV);
        }
    } else {
        if(no -> op != OP_ALEA){
            printf("%s -> ", printOperador(no -> op));
        }
    }
}

/* JVM */
void printInit(FILE *f){
	fprintf(f, ".class public JVM\n");
	fprintf(f, ".super java/lang/Object\n\n");

	fprintf(f, ".method public <init>()V\n");
	fprintf(f, "\taload_0\n\n");
	fprintf(f, "\tinvokenonvirtual java/lang/Object/<init>()V\n");
	fprintf(f, "\treturn\n");
	fprintf(f, ".end method\n\n");
	fprintf(f, ".method public static main([Ljava/lang/String;)V\n");
	fprintf(f, "\t.limit stack 10\n");	
	fprintf(f, "\t.limit locals 10\n");
}
void printEnd(FILE *f){
	fprintf(f, "\treturn\n");
	fprintf(f, ".end method\n");
}
void buildJVM(struct ArvSint *no){
    FILE *f = fopen("JVM.j", "w");
    printInit(f);
    buildJVMUtil(f, no);
    printEnd(f);
    fclose(f);
}
void buildJVMPost(FILE *f, struct ArvSint *no){
    if(no == NULL) return;
    buildJVMPost(f, no -> ptr1);
    buildJVMPost(f, no -> ptr2);
    buildJVMPost(f, no -> ptr3);
    buildJVMPost(f, no -> ptr4);

    if(no -> op == OP_ADD){
        fprintf(f, "\t%cadd\n", (no -> tipo == TIPO_FLOAT ? 'f' : 'i'));
    } else if(no -> op == OP_SUB){
        fprintf(f, "\t%csub\n", (no -> tipo == TIPO_FLOAT ? 'f' : 'i'));
    } else if(no -> op == OP_MULT){
        fprintf(f, "\t%cmul\n", (no -> tipo == TIPO_FLOAT ? 'f' : 'i'));
    } else if(no -> op == OP_DIV){
        fprintf(f, "\t%cdiv\n", (no -> tipo == TIPO_FLOAT ? 'f' : 'i'));
    } else if(no -> op == OP_INTTOFLOAT){
        fprintf(f, "\ti2f\n");
    } else if(no -> op == OP_FLOATTOINT){
        fprintf(f, "\tf2i\n");
    } else if(no -> tipo == TIPO_ID){
        fprintf(f, "\t%cload %d\n", (consultaTipoTabSimb(no -> value.id) == TIPO_FLOAT ? 'f' : 'i'), consultaPosiTabSimb(no -> value.id));
    } else if(no -> tipo == TIPO_STRING){
		fprintf(f, "\tldc %s\n", no -> value.stringV);
    } else if(no -> tipo == TIPO_INT){
        if(no -> value.intV >= 0 && no -> value.intV <= 5){
            fprintf(f, "\ticonst_%d\n", no -> value.intV);
        } else if(no -> value.intV >= -128 && no -> value.intV <= 127){
            fprintf(f, "\tbipush %d\n", no -> value.intV);
        } else {
            fprintf(f, "\tldc %d\n", no -> value.intV);
        }
    } else if(no -> tipo == TIPO_FLOAT){
        if(no -> value.floatV == 0.0 || no -> value.floatV == 1.0 || no -> value.floatV == 2.0){
            fprintf(f, "\tfconst_%d\n", (int)no -> value.floatV);
        } else {
            fprintf(f, "\tldc %f\n", no -> value.floatV);
        }
    }

}
void buildJVMUtil(FILE *f, struct ArvSint *no){
    if(no == NULL) return;
    if(no -> op == OP_ATRIB){
		if(no -> ptr2 -> op == OP_ATRIB){
			buildJVMUtil(f, no -> ptr2);			
			fprintf(f, "\t%cload %d\n", (consultaTipoTabSimb(no -> ptr2 -> ptr1 -> value.id) == TIPO_FLOAT ? 'f' : 'i'), consultaPosiTabSimb(no -> ptr2 -> ptr1 -> value.id));
		} else {
			buildJVMPost(f, no -> ptr2);
		}
        fprintf(f, "\t%cstore %d\n", (consultaTipoTabSimb(no -> ptr1 -> value.id) == TIPO_FLOAT ? 'f' : 'i'), consultaPosiTabSimb(no -> ptr1 -> value.id));
    } else if(no -> op == OP_PRINT){
        fprintf(f, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        buildJVMPost(f, no -> ptr1);
        fprintf(f, "\tinvokevirtual java/io/PrintStream/print(%s)V\n", (no -> tipo == TIPO_FLOAT ? "F" : (no -> tipo == TIPO_INT ? "I" : "Ljava/lang/String;")));
	} else if(no -> op == OP_IF){
		if(no -> ptr3 == NULL){
			int lv = label++;
			int lf = label++;
			gerarExprLogRel(f, no -> ptr1, lv, lf);
			fprintf(f, "F%d:\n", lv);
			buildJVMUtil(f, no -> ptr2);
			fprintf(f, "F%d:\n", lf);
		} else {
			int lv = label++;
			int lf = label++;
			int laux = label++;
			gerarExprLogRel(f, no -> ptr1, lv, lf);
			fprintf(f, "F%d:\n", lv);
			buildJVMUtil(f, no -> ptr2);
			fprintf(f, "\tgoto F%d\n", laux);
			fprintf(f, "F%d:\n", lf);
			buildJVMUtil(f, no -> ptr3);
			fprintf(f, "F%d:\n", laux);
		}
	} else if(no -> op == OP_WHILE){
		int lv = label++;
		int lf = label++;
		gerarExprLogRel(f, no -> ptr1, lv, lf);
		fprintf(f, "F%d:\n", lv);
		buildJVMUtil(f, no -> ptr2);
		gerarExprLogRel(f, no -> ptr1, lv, lf);
		fprintf(f, "F%d:\n", lf);
	} else if(no -> op == OP_FOR){
		buildJVMUtil(f, no -> ptr1);
		int lv = label++;
		int lf = label++;
		gerarExprLogRel(f, no -> ptr2, lv, lf);
		fprintf(f, "F%d:\n", lv);
		buildJVMUtil(f, no -> ptr4);
		buildJVMUtil(f, no -> ptr3);
		gerarExprLogRel(f, no -> ptr2, lv, lf);
		fprintf(f, "F%d:\n", lf);
	} else {
        buildJVMUtil(f, no -> ptr3);
        buildJVMUtil(f, no -> ptr2);
        buildJVMUtil(f, no -> ptr1);
    }
}
int ehTipoFloat(struct ArvSint *no){
	return (no -> tipo == TIPO_FLOAT || (no -> tipo == TIPO_ID && consultaTipoTabSimb(no -> value.id) == TIPO_FLOAT));
}
void gerarExprLogRel(FILE *f, struct ArvSint *no, int lv, int lf){
	int laux;
	switch(no -> op){
		case OP_MENOR:
			buildJVMPost(f, no -> ptr1);
			if(ehTipoFloat(no -> ptr1)){
				fprintf(f, "\tf2i\n");
			}
			buildJVMPost(f, no -> ptr2);
			if(ehTipoFloat(no -> ptr2)){
				fprintf(f, "\tf2i\n");
			}
			fprintf(f, "\tif_icmplt F%d\n", lv);
			fprintf(f, "\tgoto F%d\n", lf);
			break;
		case OP_MAIOR:
			buildJVMPost(f, no -> ptr1);
			if(ehTipoFloat(no -> ptr1)){
				fprintf(f, "\tf2i\n");
			}
			buildJVMPost(f, no -> ptr2);
			
			if(ehTipoFloat(no -> ptr2)){
				fprintf(f, "\tf2i\n");
			}
			
			printf("ptr1Tipo: %d\tptr2Tipo: %d\n", no -> ptr1 -> tipo, no -> ptr2 -> tipo);
			
			fprintf(f, "\tif_icmpgt F%d\n", lv);
			fprintf(f, "\tgoto F%d\n", lf);
			break;
		case OP_MAIORIG:
			buildJVMPost(f, no -> ptr1);
			if(ehTipoFloat(no -> ptr1)){
				fprintf(f, "\tf2i\n");
			}
			buildJVMPost(f, no -> ptr2);
			if(ehTipoFloat(no -> ptr2)){
				fprintf(f, "\tf2i\n");
			}
			fprintf(f, "\tif_icmpge F%d\n", lv);
			fprintf(f, "\tgoto F%d\n", lf);
			break;
		case OP_MENORIG:
			buildJVMPost(f, no -> ptr1);
			if(ehTipoFloat(no -> ptr1)){
				fprintf(f, "\tf2i\n");
			}
			buildJVMPost(f, no -> ptr2);
			if(ehTipoFloat(no -> ptr2)){
				fprintf(f, "\tf2i\n");
			}
			fprintf(f, "\tif_icmple F%d\n", lv);
			fprintf(f, "\tgoto F%d\n", lf);
			break;
		case OP_CMP:
			buildJVMPost(f, no -> ptr1);
			if(ehTipoFloat(no -> ptr1)){
				fprintf(f, "\tf2i\n");
			}
			buildJVMPost(f, no -> ptr2);
			if(ehTipoFloat(no -> ptr2)){
				fprintf(f, "\tf2i\n");
			}
			fprintf(f, "\tif_icmpeq F%d\n", lv);
			fprintf(f, "\tgoto F%d\n", lf);
			break;
		case OP_DIF:
			buildJVMPost(f, no -> ptr1);
			if(ehTipoFloat(no -> ptr1)){
				fprintf(f, "\tf2i\n");
			}
			buildJVMPost(f, no -> ptr2);
			if(ehTipoFloat(no -> ptr2)){
				fprintf(f, "\tf2i\n");
			}
			fprintf(f, "\tif_icmpne F%d\n", lv);
			fprintf(f, "\tgoto F%d\n", lf);
			break;
		case OP_AND:
			laux = label++;
			gerarExprLogRel(f, no -> ptr1, laux, lf);
			fprintf(f, "F%d:\n", laux);
			gerarExprLogRel(f, no -> ptr2, lv, lf);
			break;
		case OP_OR:
			laux = label++;
			gerarExprLogRel(f, no -> ptr1, lv, laux);
			fprintf(f, "F%d:\n", laux);
			gerarExprLogRel(f, no -> ptr2, lv, lf);
			break;
		case OP_NOT:
			gerarExprLogRel(f, no -> ptr1, lf, lv);
			break;
	}
}

/* Graphviz */
void createGraphviz(struct ArvSint *no){
    FILE *f = fopen("graph.dot", "w");
    int cnt = 0;
    fprintf(f, "digraph G {\n");
    createGraphvizMarca(f, no, &cnt);
    createGraphvizFinaliza(f, no);
    fprintf(f, "}\n");
    fclose(f);
}
void createGraphvizMarca(FILE *f, struct ArvSint *no, int *cnt){
    if(no == NULL) return;
    (*cnt)++;
    no -> graphID = *cnt;
    if(no -> op == -1){
        if(no -> tipo == TIPO_INT){
            fprintf(f, "\t%d [label = \"%d\"];\n", *cnt, no -> value.intV);
        } else if(no -> tipo == TIPO_FLOAT){
            fprintf(f, "\t%d [label = \"%.2f\"];\n", *cnt, no -> value.floatV);
        } else if(no -> tipo == TIPO_ID){
            fprintf(f, "\t%d [label = \"%s\"];\n", *cnt, no -> value.id);
        } else {
            fprintf(f, "\t%d [label = %s];\n", *cnt, no -> value.stringV);
        }
    } else if(no -> op != OP_ALEA){
        fprintf(f, "\t%d [label = \"%s\"];\n", *cnt, printOperador(no -> op));
    }
    createGraphvizMarca(f, no -> ptr1, cnt);
    createGraphvizMarca(f, no -> ptr2, cnt);
    createGraphvizMarca(f, no -> ptr3, cnt);
    createGraphvizMarca(f, no -> ptr4, cnt);
}
void createGraphvizFinaliza(FILE *f, struct ArvSint *no){
    if(no -> ptr1 != NULL){
        fprintf(f, "\t%d -> %d;\n", no -> graphID, no -> ptr1 -> graphID);
        createGraphvizFinaliza(f, no -> ptr1);
    }
    if(no -> ptr2 != NULL){
        fprintf(f, "\t%d -> %d;\n", no -> graphID, no -> ptr2 -> graphID);
        createGraphvizFinaliza(f, no -> ptr2);
    }
    if(no -> ptr3 != NULL){
        fprintf(f, "\t%d -> %d;\n", no -> graphID, no -> ptr3 -> graphID);
        createGraphvizFinaliza(f, no -> ptr3);
    }
    if(no -> ptr4 != NULL){
		fprintf(f, "\t%d -> %d;\n", no -> graphID, no -> ptr4 -> graphID);
        createGraphvizFinaliza(f, no -> ptr4);
	}
}

/* Tabela de Simbolos */
int hash(char *id){
    int n, i;
	int hash = n = strlen(id);
	for (i = 0; i < n; i++) {
		hash = (hash * (id[i] + i) ^ 843273) % MAX_HASH;
		if (hash < 0) hash = -hash;
	}
	return hash;
}
int consultaTipoTabSimb(char *nome){
    int h = hash(nome);
    if(tabSimb[h].lista == NULL) return -1;
    NoLDDE *no = tabSimb[h].lista -> inicioLista;
    while(no != NULL){
        stuff *aux = (stuff *)no -> dados;
        if(strcmp(aux -> id, nome) == 0){
            return aux -> tipo;
        }
        no = no -> prox;
    }
    return -1;
}
int consultaPosiTabSimb(char *nome){
    int h = hash(nome);
    if(tabSimb[h].lista == NULL) return -1;
    NoLDDE *no = tabSimb[h].lista -> inicioLista;
    while(no != NULL){
        stuff *aux = (stuff *)no -> dados;
        if(strcmp(aux -> id, nome) == 0){
            return aux -> posicao;
        }
        no = no -> prox;
    }
    return -1;
}
void insereTabSimbolo(LDDE *p, int tipo){
    NoLDDE * no = p -> inicioLista;
    while(no != NULL) {
        char tmp[11];
        strcpy(tmp, (char *)((stf *)no->dados) -> id);
        int h = hash(tmp);

        stuff *_tmp = (stuff *)malloc(sizeof(stuff));
        stf *tmmp = (stf *)malloc(sizeof(stf));
        tmmp = no -> dados;
        strcpy(_tmp->id, tmmp -> id);
        _tmp->tipo = tipo;
        _tmp -> posicao = tmmp -> posicao;

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
void printTabSimb(){
    int i = 0;
    printf("%-10s%9s%20s\n", "ID", "Tipo", "Posicao");
    for(i = 0; i < MAX_HASH; i++) {
        if(tabSimb[i].lista != NULL) {
            NoLDDE * no = tabSimb[i].lista -> inicioLista;
            while(no != NULL) {
                stuff *aux = (stuff *)no->dados;
                printf("%-15s%-15s%d\n", aux -> id, (aux -> tipo == 1 ? "INT" : (aux -> tipo == 2 ? "STRING" : "FLOAT")), aux -> posicao);
                no = no->prox;
            }
        }
    }
}

/* Ver se o numero e float ou int */
int ehFloat(char *num){
    char *aux = num;
    int f = 0;
    while(*aux != '\0'){
        if(*aux == '.'){
            f = 1;
            break;
        }
        aux++;
    }
    return f;
}
