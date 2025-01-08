#include <stdio.h>
#include <stdlib.h>

struct sNODE {
    int dado;
    struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);

int main(void) {
    printf("Hello World\n");
    return 0;
}

void inserir(int dado)
{
    struct sNODE *aux = malloc(sizeof(struct sNODE));
    aux->dado = dado;
    aux->prox = NULL;

    if (ini == NULL)
    {
        ini = aux;
        fim = aux;
    }
    else
    {
        fim->prox = aux; // O elemento sucessor de fim que era NULL agora recebe o nosso novo dado (aux)

        fim = aux; // ou fim = fim->prox;
    }
}

struct sNODE *buscar(int dado) {
    struct sNODE *aux = ini;
    while (aux != NULL) {
        // alguma coisa
        if (aux->dado == dado) {
            return aux;
        }

        // indo para o próximo elemento
        aux = aux->prox;
    }
    return NULL;
}

void remover(int dado) {
    struct sNODE *aux = ini;
    struct sNODE *ant = NULL;
    while (aux != NULL) {
        if (aux->dado == dado) {
            if (aux == ini) {
                ini = aux->prox; // ou ini = ini->prox;
            }
            else if (aux == fim) {
                fim = ant;
                fim->prox = NULL;
            }
            else {
                ant->prox = aux->prox;
            }
            free(aux);
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
}

void apagar(){
    struct sNODE *aux = ini;
    struct sNODE *ant = NULL;

    while (aux != NULL){ //Enquanto aux avança o anterior à aux vai sendo apagado
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    ini = fim = NULL; //Atualizando elementos da lista
}

void imprimir(){
    struct sNODE *aux = ini;

    printf("[");

    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }

    printf("]\n");
}

