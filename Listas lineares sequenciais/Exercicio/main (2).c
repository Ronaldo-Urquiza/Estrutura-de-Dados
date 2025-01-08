#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 10;
    //10 strings cada uma com 21 caracteres incluindo o \0
char l[MAX][21], pos = 0;
    //grande sacada da questão
void inserir_ord(char *elemento);

int buscar(char *elemento);
void remover(char *elemento);
char* obter(int indice);
 
int tamanho();
void imprimir();
void apagar();

//Só troquei as operações que se fazem com números por operações próprias para strings
void inserir_ord(char *elemento){
  int i, p;
  if (pos < MAX) {
  for (i = 0 ; i < pos ; i++)
      if (strcmp(l[i], elemento) >= 0)
              break;

  for (p = pos ; p > i ; p--)
        strcpy(l[p], l[p-1]);  //percorrendo lista de trás p frente e movendo strings

  strcpy(l[i],elemento); //inserindo elemento na posição correta

  pos ++;
  }
  else {
  printf("Não foi possível inserir %s. Lista cheia.\n", elemento);
  }
}

int buscar(char *elemento){
  for (int i = 0 ; i < pos ; i++){
  if (strcmp(l[i],elemento)==0)
    return i;
  }
  return -1;
}

void remover(char *elemento){
  int p = buscar(elemento);

  if (p == -1)
  return;

  for (int i = p ; i < pos -1; i++)
  strcpy(l[i], l[i+1]);
  pos--;
}

char* obter(int indice){
  if (indice < 0 || indice >= pos) {
  printf("Indice %d fora dos limites da Lista.\n", indice);
  exit(1);
  }
  return l[indice];
}

int tamanho(){
  return pos;
} 

void imprimir(){
  if(pos == 0){printf("Lista vazia.\n"); return;}
  for (int i = 0 ; i < pos ; i++)
  printf("%s ",l[i]);
  printf("\n");
}

void apagar(){
  pos = 0;
}

int main(void) {

  inserir_ord("abacate");
  inserir_ord("zabacate");
  inserir_ord("babacate");
  inserir_ord("abacate");
  inserir_ord("kabacate");
  imprimir();
  
  printf("\n");
  printf("Testando funções: \n");
  
  printf("Tamanho: %d\n",tamanho());
  printf("\n");
  printf("Alvo: termo 2 (babacate) \n");
  printf("Buscar: %d\n", buscar("babacate"));
  printf("Obter: %s\n", obter(2));

  printf("\n");
  printf("Testando remover, alvo: babacate \n");
  remover("babacate");
  imprimir();

  printf("\n");
  printf("Testando apagar: \n");
  apagar();
  imprimir();
  
  return 0;
}