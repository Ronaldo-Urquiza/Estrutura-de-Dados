#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

int getTopo();

void push(int elemento);
int pop();

int tamanho();
void imprimir();
void apagar();

int main(void) {

  push(1);
  push(2);
  push(3);
  push(4);

  printf("\nElemento: %d\n",getTopo());
  
}

int getTopo(){
  if (pos)
    return l[pos-1]; //POS -1 POIS POS É A PROXIMA POSIÇÃO LIVRE
  else{
    printf("Não há elementos. Pilha vazia.\n");
    exit(1);
  }
}

void push(int elemento){
  if (pos < MAX)
  l[pos++] = elemento; 
  else
  printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

int pop(){
  if (pos)
  return l[--pos]; //TIRA 1 DE POS E DEPOIS PEGA O ELEMENTO 
  else {
  printf("Não há elementos. Pilha vazia.\n");
  exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("P[ ");
  for (int i = pos -1 ; i >= 0 ; i--)
  printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}