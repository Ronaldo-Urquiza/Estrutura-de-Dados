#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void enqueue(int dado);
int dequeue();
struct sNODE *buscar(int dado);

int obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){
      
  printf("\nLista original: \n");
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);

  imprimir();

  printf("\nLista após dequeue: \n");    
  dequeue();

  imprimir();
      
  return 0;
}

void enqueue(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
  ini = fim = novo;
  else{
  fim->prox = novo;
  fim = novo;
  }
}

struct sNODE *buscar(int dado){
  struct sNODE *aux = ini;

  while (aux){
  if (dado == aux->dado)
        return aux;
  aux = aux->prox;
  }

  return NULL;
}

int dequeue(){

      struct sNODE *aux = ini, *ant = NULL;

      int pop = aux->dado;

      ini = aux->prox;

      free(aux);

      return pop;
}

void apagar(){
  struct sNODE *aux = ini, *ant;

  while (aux){
  ant = aux;
  aux = aux->prox;
  free(ant);
  }
  ini = fim = NULL;
}

int obter(struct sNODE *node){
  if (!node){
  printf("Erro ao obter dado. Ponteiro invalido.");
  exit(0);
  }

  return node->dado;
}

int tamanho(){
  struct sNODE *aux = ini;
  int tam = 0;

  while (aux){
  tam++;
  aux = aux->prox;
  }

  return tam;
}

void imprimir(){
  struct sNODE *aux = ini;

  printf("[ ");
  while (aux){
  printf("%d ", aux->dado);
  aux = aux->prox;
  }
  printf("]\n");
}

