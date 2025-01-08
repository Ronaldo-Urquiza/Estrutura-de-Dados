#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int main(void) {

  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);

  printf("\nFila original\n");
  imprimir();
  printf("\nTamanho da fila: %d\n", tamanho());


  printf("\nElemento removido: %d\n", dequeue());
  printf("\nFila após dequeue\n");
  imprimir();
  printf("\nTamanho da fila: %d\n", tamanho());
  
  return 0;
}


void enqueue(int elemento){
  if (pos < MAX)
  l[pos++] = elemento;
  else {
  printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

int dequeue(){
  
  int pop = 0;

  pop = l[0];
  
  for (int i = 0 ; i < pos -1; i++)
  l[i] = l[i+1];
  pos--;

  return pop;
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("Fila: [ ");
  for (int i = 0; i<pos ; i++)
  printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}