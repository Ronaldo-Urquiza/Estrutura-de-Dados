#include <stdio.h>
#include <stdlib.h>

struct sNODE {
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void remover(int dado);
struct sNODE *buscar(int dado);

int obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

void inserir_ord(int dado);

int main(void) {

  return 0;
}

void inserir(int dado) {
  struct sNODE *no = (struct sNODE *) malloc(sizeof(struct sNODE));
  no->dado = dado;
  no->prox = NULL;
  no->ant = NULL;
  if (ini == NULL) {
    ini = fim = no;
  } else {
    fim->prox = no;
    no->ant = fim;
    fim = no;
  }
}

struct sNODE *buscar(int dado) {
  struct sNODE *aux = ini;
  while (aux != NULL) {
    if (aux->dado == dado)
      return aux;
    aux = aux->prox;
  }
  return NULL;
}

void remover(int dado) {
  struct sNODE *aux = buscar(dado);
  if (aux == NULL)
    return;

  if (ini == fim) {
    ini = fim = NULL;
  } else if (aux == ini) {
    ini = ini->prox;
    ini->ant = NULL;
  } else if (aux == fim) {
    fim = fim->ant;
    fim->prox = NULL;
  } else {
    // (*(*aux).ant).prox = (*aux).prox;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
  }
  free(aux);
}

int obter(struct sNODE *node) {
  if (node != NULL)
    return node->dado;
  exit(1);
}

int tamanho() {
  struct sNODE *aux = ini;
  int contador = 0;
  while (aux != NULL) {
    contador++;
    aux = aux->prox;
  }
  return contador;
}

void imprimir() {
  // com espaço entre os elementos
  struct sNODE *aux = ini;
  printf("[ ");
  while (aux != NULL) {
    printf("%d ", aux->dado);
  }
  printf("]\n");

  /* com virgula entre os elementos
  printf("[");
  while (aux != NULL) {
    printf("%d", aux->dado);
    if (aux->prox != NULL)
      printf(", ");
  }
  printf("]");
  */
}

void apagar() {
  struct sNODE *aux = ini, *ant = NULL;
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
}

void inserir_ord(int dado) {
  struct sNODE *no = (struct sNODE *) malloc(sizeof(struct sNODE));
  no->dado = dado;
  no->ant = NULL;
  no->prox = NULL;

  struct sNODE *aux = ini;
  while (aux != NULL && aux->dado < dado)
    aux = aux->prox;

  if (ini == NULL)
    ini = fim = no;
  else if (aux == ini) {
    ini->ant = no;
    no->prox = ini;
    ini = no;
  } else if (aux == NULL) {
    fim->prox = no;
    no->ant = fim;
    fim = no;
  } else {
    aux->ant->prox = no;
    no->ant = aux->ant;
    no->prox = aux;
    aux->ant = no;
  }
}