#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Configura a estrutura do/s nó/s da lista
struct sNODE { 
  char *nome; 
  double nota1, nota2, media;
  struct sNODE *prox; 
};

//Criação de lista múltiplas----------------------------
struct sLISTA{
  struct sNODE *ini, *fim; //Cada lista tem início e fim
};

//Defina que 
        //a variável do tipo struct sLISTA
                      //pode ser criada com a palavra LISTA
typedef struct sLISTA LISTA; 
//-----------------------------------------------------

//Assinatura das novas funções-------------------------
void inicializar(LISTA *lst);
void inserir_aluno(LISTA *lst, char *nome, double nota1, double nota2, double media);
void imprimir(LISTA *lst);

void apagar(LISTA *lst);

void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);
int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);
//----------------------------------------------------

//Main
int main(void) {

  LISTA lst;
  inicializar(&lst);
  
  inserir_aluno(&lst, "Adrian Fahrenheit Tepes", 10, 10, 10);
  inserir_aluno(&lst, "Sypha Belnades", 9, 9, 9);
  inserir_aluno(&lst, "Trevor Belmont", 5, 5, 5);
  inserir_aluno(&lst, "Dracula Vlad Tepes", 8, 8, 8);

  imprimir(&lst);
  
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir_aluno(LISTA *lst, char *nome, double nota1, double nota2, double media){
  
  struct sNODE *aux = lst->ini;
  struct sNODE *ant = NULL;

  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  
  novo->nome = malloc(sizeof(char)*(strlen(nome)+1));
  strcpy(novo->nome, nome);
  novo->nota1 = nota1;
  novo->nota2 = nota2;
  novo->media = media;
  novo->prox = NULL;

  while(aux && aux->media < novo->media){ //Acha a posição de inserção do aluno
    ant = aux; //Avança ant
    aux = aux->prox; //Avança aux
  }

  //Se o início for nulo, o novo nó será o início e o fim
  if (lst->ini == NULL){ // !lst->ini
    lst->ini = lst->fim = novo;
  }

  //Se por acaso o dado precise ser inserido no ini da lista
  else if (aux == lst->ini){
    novo->prox = lst->ini; //O sucesso do novo nó recebe o início da lista
    lst->ini = novo; //O início da lista recebe o novo nó
  } 

  //Se o dado precisa ser inserido no fim da lista (aux não nulo)
  else if (!aux){//aux==NULL
    lst->fim->prox = novo; //O sucessor do fim da lista recebe o novo nó
    lst->fim = novo; //O fim da lista recebe o novo nó
  } 

  else { //Se o dado pecisa ser inserido no meio da lista
    ant->prox = novo; //O sucesso de anterior recebe o novo nó
    novo->prox = aux; //O sucessor do novo nó recebe o atual auxiliar
  }
  
}

void imprimir(LISTA *lst) {
  
  struct sNODE *aux = lst->ini; //Cria variável auxiliar para percorrer a lista

  while (aux != NULL) {  //Enquanto não achar o aterramento da lista

    printf("\n");
    printf("Aluno(a): %s ", aux->nome);
    printf("\nNota1: %.2lf ", aux->nota1); 
    printf("\nNota2: %.2lf ", aux->nota2); 
    printf("\nMedia: %.2lf ", aux->media); 
    printf("\n");
    
    aux = aux->prox;  //Avançe aux
  }

}