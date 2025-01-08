#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct sPILHA{
  int pos;
  char *arr;
  int MAX;
};

typedef struct sPILHA PILHA;

void inversor(PILHA *pi, char *string, int tam, int palavras);

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);
int contarPalavras(const char *str);

void push(PILHA *pi, char dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

int main(void) {

  PILHA pilha1;
  criar(&pilha1, 100);

  char string[100];
  printf("Digite uma string: ");
  fgets(string, sizeof(string), stdin); //ESTRUTURA DE DADOS EH BOM DEMAIS

  // Remover o '\n' da string
  string[strcspn(string, "\n")] = '\0';

  int tamanho = strlen(string);

  int palavras = contarPalavras(string);
  //printf("%d",palavras);
  
  inversor(&pilha1, string, tamanho, palavras);
  
  //imprimir(&pilha1);

  return 0;
}

// Função para contar o número de palavras em uma string
int contarPalavras(const char *str) {
    int contador = 0;
    int dentroDaPalavra = 0; // Flag para verificar se estamos dentro de uma palavra

    while (*str) { // Percorre cada caractere da string
        if (isspace(*str)) { // Verifica se o caractere é um espaço
            dentroDaPalavra = 0; // Marca que estamos fora de uma palavra
        } else if (!dentroDaPalavra) { // Se não estamos dentro de uma palavra
            dentroDaPalavra = 1; // Marca que estamos dentro de uma palavra
            contador++; // Conta a nova palavra
        }
        str++; // Avança para o próximo caractere
    }

    return contador; // Retorna o número total de palavras
}

void inversor(PILHA *pi, char *string, int tam, int palavras){
  int count = 0;
  int indice = 0;
  
  while (count < palavras && indice < tam) {
    
    // Empilha caracteres da palavra atual
    while (indice < tam && string[indice] != ' ') {
        push(pi, string[indice]);
        indice++;
    }

    // Desempilha e imprime a palavra atual
    while (tamanho(pi) > 0) {
        printf("%c", pop(pi));
    }
    printf(" ");

    // Atualizar indice quando encontrar um espaço
    while (indice < tam && string[indice] == ' ') {
        indice++;
    }

    count++;
  }
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
  printf("Pilha: ");
  for (int i = pi->pos -1 ; i >= 0 ; i--)
  printf("%c",pi->arr[i]);
  printf("\n");
}