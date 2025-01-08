#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  char nome[30];
  char ocupacao[30];
  double salario;

  struct sNODE *ant;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);

void inserir_ord(LISTA *lst, char nome[30], char ocupacao[30], double salario);

void imprimir(LISTA *lst);

void apagar(LISTA *lst);

int main(){
  LISTA lst;
  inicializar(&lst);
  inserir_ord(&lst, "Trevor Belmont", "Caçador de Vampiros", 1000);
  inserir_ord(&lst, "Sypha", "Speaker", 120);
  inserir_ord(&lst, "Drácula", "Dono de castelo", 800000);
  inserir_ord(&lst, "Alucard", "Príncipe", 250000);
  imprimir(&lst);
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir_ord(LISTA *lst, char nome[30], char ocupacao[30], double salario) {
  struct sNODE *no = (struct sNODE *) malloc(sizeof(struct sNODE));
  
  strcpy(no->nome, nome);
  strcpy(no->ocupacao, ocupacao);
  no->salario = salario;
  
  no->ant = NULL;
  no->prox = NULL;

  struct sNODE *aux = lst->ini;
  
  while (aux != NULL && aux->salario < salario){
    aux->ant = aux; //Avança ant
    aux = aux->prox;//Avança ant
  }

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

void imprimir(LISTA *lst) {

  struct sNODE *aux = lst->ini; //Cria variável auxiliar para percorrer a lista

  while (aux != NULL) {  //Enquanto não achar o aterramento da lista

    printf("\n");
    printf("Profissional: %s ", aux->nome);
    printf("\nOcupação: %s", aux->ocupacao); 
    printf("\nSalário: %.2lf ", aux->salario); 
    printf("\n");

    aux = aux->prox;  //Avançe aux
  }

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