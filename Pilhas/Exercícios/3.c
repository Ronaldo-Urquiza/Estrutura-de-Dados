#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPILHA{
  int pos;
  char *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);
void verifica(PILHA *pi);

void push(PILHA *pi, char dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

int main(void) {

  PILHA pilha1;
  criar(&pilha1, 100);

  char string[100];
  printf("Digite uma string: ");
  fgets(string, sizeof(string), stdin); //{[()]}({

  int tamanho = strlen(string);

  for(int i = 0; i < tamanho; i++){
    push(&pilha1, string[i]);
  }

  
  imprimir(&pilha1);

  verifica(&pilha1);

  return 0;
}

void verifica(PILHA *pi){

  int countPaAberto = 0;   // Contador de parênteses abertos '('
  int countPaFechado = 0;  // Contador de parênteses fechados ')'

  int countChAberto = 0;   // Contador de chaves abertas '{'
  int countChFechado = 0;  // Contador de chaves fechadas '}'

  int countCoAberto = 0;   // Contador de colchetes abertos '['
  int countCoFechado = 0;  // Contador de colchetes fechados ']
  
  //Percorrer pilha da base até o topo
  for(int i = 0; i < pi->pos; i++){
      //Conta os parenteses
      if(pi->arr[i] == '('){
        countPaAberto++;
      }
      //Conta as chaves
      else if(pi->arr[i] == '{'){
        countChAberto++;
      }
      //Conta as chaves
      else if(pi->arr[i] == '['){
        countCoAberto++;
      }
      //Conta os parenteses
      else if(pi->arr[i] == ')'){
        countPaFechado++;
      }
      //Conta as chaves
      else if(pi->arr[i] == '}'){
        countChFechado++;
      }
      //Conta as chaves
      else if(pi->arr[i] == ']'){
        countCoFechado++;
      } 
    }

  if (countPaAberto == countPaFechado) {printf("\nParênteses balanceados\n");} else{printf("\nParênteses desbalanceados\n");}
  if (countChAberto == countChFechado) {printf("\nChaves balanceadas\n");} else{printf("\nChaves desbalanceadas\n");}
  if (countCoAberto == countCoFechado) {printf("\nColchetes balanceados\n");} else{printf("\nColchetes desbalanceados\n");}
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
  printf("Pilha ->  ");
  for (int i = pi->pos -1 ; i >= 0 ; i--)
  printf("%c ",pi->arr[i]);
  printf("\n");
}