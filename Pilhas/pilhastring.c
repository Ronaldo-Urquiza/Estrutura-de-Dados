#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int pos;
  char *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);

void push(PILHA *pi, char dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

int main(void) {

  PILHA pilha1;
  criar(&pilha1, 100);

  push(&pilha1,'A');
  push(&pilha1,'B');
  push(&pilha1,'A');
  push(&pilha1,'C');
  push(&pilha1,'A');
  push(&pilha1,'T');
  push(&pilha1,'E');

  imprimir(&pilha1);

  return 0;
}

void criar(PILHA *pi, int tam_MAX){
  pi->pos = 0;
  pi->arr = (char*) malloc(tam_MAX * sizeof(char));  // Agora aloca espaço para uma string
  pi->MAX = tam_MAX;
}

void apagar(PILHA *pi){
  free(pi->arr);
  pi->arr = NULL;             
  pi->pos = 0;                  
  pi->MAX = 0;   
}

void push(PILHA *pi, char dado){
  if (pi->pos < pi->MAX)
    pi->arr[pi->pos++] = dado;
  else
  printf("Não foi possível inserir o caractere: ""%c"". Pilha cheia.\n", dado);
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
  printf("%c ",pi->arr[i]);
  printf("]\n");
}