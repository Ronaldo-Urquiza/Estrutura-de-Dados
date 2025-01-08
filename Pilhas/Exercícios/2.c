#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int pos, *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);

void push(PILHA *pi, int dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

int main(void) {

  PILHA pilha1;
  criar(&pilha1, 10);

  push(&pilha1, 100);
  push(&pilha1, 50);
  push(&pilha1, 200);

  PILHA pilha2;
  criar(&pilha2, 10);

  push(&pilha2, 10);
  push(&pilha2, 5);
  push(&pilha2, 20);
  
  printf("\nPilha 1: "); imprimir(&pilha1);
  printf("\nPilha 2: "); imprimir(&pilha2);
  
  printf("\nPop do elemento %d na Pilha 1\n",pop(&pilha1));

  printf("\nPilha 1: "); imprimir(&pilha1);
  printf("\nPilha 2: "); imprimir(&pilha2);

  printf("\nApagando pilha 1...\n");
  apagar(&pilha1);

  printf("\nPilha 1: "); imprimir(&pilha1);
  printf("\nPilha 2: "); imprimir(&pilha2);

  return 0;
}

void criar(PILHA *pi, int tam_MAX){
  pi->pos = 0;
  pi->arr = malloc(tam_MAX * sizeof(int));
  pi->MAX = tam_MAX;
}

void apagar(PILHA *pi){
  free(pi->arr);
  pi->arr = NULL;             
  pi->pos = 0;                  
  pi->MAX = 0;   
}

void push(PILHA *pi, int dado){
  if (pi->pos < pi->MAX)
    pi->arr[pi->pos++] = dado;
  else
  printf("Não foi possível inserir %d. Pilha cheia.\n", dado);
}

int pop(PILHA *pi){
  if (pi->pos)
  return pi->arr[--pi->pos];
  else {
  printf("Não há elementos. Pilha vazia.\n");
  exit(1);
  }
}

int tamanho(PILHA *pi){
  return pi->pos;
}

void imprimir(PILHA *pi){
  printf("P[ ");
  for (int i = pi->pos -1 ; i >= 0 ; i--)
  printf("%d ",pi->arr[i]);
  printf("]\n");
}