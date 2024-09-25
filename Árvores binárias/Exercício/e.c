#include <stdio.h>
#include <stdlib.h>

struct sNODE {
    int dado;
    struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;

int alturaArvore(struct sNODE *no);

struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado);

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);
struct sNODE *apagar(struct sNODE *no);

int main() {

    raiz = inserir(raiz,7);
    inserir(raiz,3);
    inserir(raiz,9);
    inserir(raiz,1);
    inserir(raiz,5);
    inserir(raiz,4);

    printf("%d",alturaArvore(raiz));
    printf("\n");

    return 0;
}

int alturaArvore(struct sNODE *raiz){

    if (raiz == NULL) {
        return -1; // Retorna -1 se o nó não existir na árvore (considera a altura da árvore vazia)
    }

    // Calcula a altura das subárvores esquerda e direita
    int alturaEsquerda = alturaArvore(raiz->esq);
    int alturaDireita = alturaArvore(raiz->dir);

    // Retorna a altura máxima das subárvores + 1 para contar a raiz
    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1; // Retorna a altura da subárvore esquerda + 1
    } else {
        return alturaDireita + 1; // Retorna a altura da subárvore direita + 1
    }
}

struct sNODE *inserir(struct sNODE *no, int dado) {
    if (!no) {
        no = (struct sNODE*) malloc(sizeof(struct sNODE));
        no->dado = dado;
        no->esq = no->dir = NULL;
    } else if (dado < no->dado) {
        no->esq = inserir(no->esq, dado);
    } else {
        no->dir = inserir(no->dir, dado);
    }
    return no;
}

struct sNODE *remover(struct sNODE *no, int dado) {
    struct sNODE *aux = NULL, *aux2 = NULL;

    if (no) {
        if (no->dado == dado) {
            if (no->esq == no->dir) {
                free(no);
                return NULL;
            } else if (!no->esq) {
                aux = no->dir;
                free(no);
                return aux;
            } else if (!no->dir) {
                aux = no->esq;
                free(no);
                return aux;
            } else {
                aux = aux2 = no->dir;
                while (aux->esq) {
                    aux = aux->esq;
                }
                aux->esq = no->esq;
                free(no);
                return aux2;
            }
        } else {
            if (dado < no->dado) {
                no->esq = remover(no->esq, dado);
            } else {
                no->dir = remover(no->dir, dado);
            }
        }
    }
    return no;
}

void emOrdem(struct sNODE *no) {
    if (no) {
        emOrdem(no->esq);
        printf("%d ", no->dado);
        emOrdem(no->dir);
    }
}

void preOrdem(struct sNODE *no) {
    if (no) {
        printf("%d ", no->dado);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void posOrdem(struct sNODE *no) {
    if (no) {
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf("%d ", no->dado);
    }
}

struct sNODE *buscar(struct sNODE *no, int dado) {
    if (no) {
        if (no->dado == dado) {
            return no;
        } else if (dado < no->dado) {
            return buscar(no->esq, dado);
        } else {
            return buscar(no->dir, dado);
        }
    }
    return NULL;
}

int obter(struct sNODE *no) {
    if (no) {
        return no->dado;
    } else {
        printf("Nenhum dado para retornar.");
        exit(0);
    }
}
