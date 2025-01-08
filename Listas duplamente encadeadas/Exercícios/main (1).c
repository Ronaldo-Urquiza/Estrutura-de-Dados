#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

void apagar(LISTA *lst);

int main(){
  LISTA lst;
  inicializar(&lst);

  inserir_ord(&lst, 100);
  inserir_ord(&lst, 100);
  inserir_ord(&lst, 200);
  inserir_ord(&lst, 300);
  
  imprimir(&lst);
  printf("Tamanho da lista: %d\n", tamanho(&lst));
  
  printf("\nDado do node ini: %d\n", obter(lst.ini));
  printf("\nDado do node fim: %d\n\n", obter(lst.fim));
  
  remover(&lst,100);
  imprimir(&lst);
  printf("Tamanho pós remover 1 elemento: %d\n", tamanho(&lst));

  apagar(&lst);
  printf("\nTamanho pós apagar: %d\n", tamanho(&lst));

  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir_ord(LISTA *lst, int dado) {
  struct sNODE *no = (struct sNODE *) malloc(sizeof(struct sNODE));
  no->dado = dado;
  no->ant = NULL;
  no->prox = NULL;

  struct sNODE *aux = lst->ini;
  while (aux != NULL && aux->dado < dado)
    aux = aux->prox;

  if (lst->ini == NULL)
    lst->ini = lst->fim = no;
  else if (aux == lst->ini) {
    lst->ini->ant = no;
    no->prox = lst->ini;
    lst->ini = no;
  } else if (aux == NULL) {
    lst->fim->prox = no;
    no->ant = lst->fim;
    lst->fim = no;
  } else {
    aux->ant->prox = no;
    no->ant = aux->ant;
    no->prox = aux;
    aux->ant = no;    
  }
}

struct sNODE *buscar(LISTA *lst, int dado) {
  struct sNODE *aux = lst->ini;
  while (aux != NULL) {
    if (aux->dado == dado)
      return aux;
    aux = aux->prox;
  }
  return NULL;
}

void remover(LISTA *lst, int dado) {
  struct sNODE *aux = buscar(lst, dado);
  if (aux == NULL)
    return;

  if (lst->ini == lst->fim) {
    lst->ini = lst->fim = NULL;
  } else if (aux == lst->ini) {
    lst->ini = lst->ini->prox;
    lst->ini->ant = NULL;
  } else if (aux ==lst-> fim) {
    lst->fim = lst->fim->ant;
    lst->fim->prox = NULL;
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

int tamanho(LISTA *lst) {
  struct sNODE *aux = lst->ini;
  int contador = 0;
  while (aux != NULL) {
    contador++;
    aux = aux->prox;  
  }
  return contador;
}

void imprimir(LISTA *lst) {
  // com espaço entre os elementos
  struct sNODE *aux = lst->ini;
  printf("[ ");
  while (aux != NULL) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void apagar(LISTA *lst) {
  struct sNODE *aux = lst->ini, *ant = NULL;
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  lst->ini = lst->fim = NULL;
}