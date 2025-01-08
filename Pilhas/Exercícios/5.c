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
  fgets(string, sizeof(string), stdin); 

  int tamanho = strlen(string);

  for(int i = 0; i < tamanho; i++){
    push(&pilha1, string[i]);
  }

  verifica(&pilha1);

  return 0;
}

void verifica(PILHA *pi){
  
  PILHA pilhaTemp;
  criar(&pilhaTemp, pi->MAX);

  int balanceado = 1;

  // Percorrer a pilha da base até o topo
  for (int i = 0; i < pi->pos; i++) {
      char ch = pi->arr[i];
    
      if (ch == '(') {
        push(&pilhaTemp, ch);
      } 
        
      else if (ch == ')') {
        if (tamanho(&pilhaTemp) == 0) { //Se pilha estiver vazia
          balanceado = 0; //então temos um ) sem um ( antes
          break; 
        } 
        else { //Se a pilha NÃO estiver vazia
          pop(&pilhaTemp); // então temos um ) com um ( antes
        }
      }
  }

  if (tamanho(&pilhaTemp) != 0) { //verifica se a pilha temporária ainda contém elementos. Se sim, então temos um partênteses "solteiros"
      balanceado = 0;
  }

  if (balanceado) {
      printf("OK\n");
  } else {
      printf("Não OK\n");
  }

  apagar(&pilhaTemp);
  
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