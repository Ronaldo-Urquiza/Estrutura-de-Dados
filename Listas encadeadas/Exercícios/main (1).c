#include <stdio.h>
#include <stdlib.h>

//Configura a estrutura do/s nó/s da lista
struct sNODE { //Configura uma variável do tipo struct chamada sNODE
  int dado; //Campo da struct do nó que receberá um dado 
  struct sNODE *prox; //Campo da struct do nó que serva para apontar para o sucessor do nó atual
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
void apagar(LISTA *lst);
void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);
int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);
//----------------------------------------------------

//Main
int main(void) {

  LISTA lst; //Criando lista chamada lst
  inicializar(&lst); //Inicializando ini e fim da lst

  printf("Inserindo 300, 200, 200, 100 na lista..\n");
  inserir_ord(&lst, 300);
  inserir_ord(&lst, 200);
  inserir_ord(&lst, 200);
  inserir_ord(&lst, 100);

  printf("\nLista pós inserção:\n");
  imprimir(&lst);
  printf("\nTamanho da lista: %d elementos\n", tamanho(&lst));

  printf("\nObtendo dado inicial e final através dos nós conhecidos da lst:\n");
  printf("Inicial: %d | Final: %d", obter(lst.ini),obter(lst.fim));
  printf("\n");
  
  printf("\nRemovendo 200 da lista..\n");
  remover(&lst, 200);

  printf("\nLista pós remoção:\n");
  imprimir(&lst);
  printf("\nTamanho da lista: %d elementos\n", tamanho(&lst));
  
  printf("\nApagando lista....\n");
  apagar(&lst);
  printf("Tamanho da lista: %d elementos\n", tamanho(&lst));
  
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini;
  struct sNODE *ant = NULL;

  while (aux != NULL){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  
  lst->ini = lst->fim = NULL;
  
}

void inserir_ord(LISTA *lst, int dado) { 

  //Cria ponteiro auxiliar que recebe o início da lista e anterior que recebe nada mas que pode ser interpretado com o que existe antes do início
  struct sNODE *aux = lst->ini, *ant = NULL;

  //AUX e ANT percorrem a lista, são os corredores

  //Aloca espaço para o novo nó
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  
  novo->dado = dado; //Atribui o valor do dado do usuário ao campo "dado" do novo nó
  novo->prox = NULL; //O campo "prox" do novo nó recebe o fim da lista

  while(aux && dado > aux->dado){//Enquanto o dado que o auxiliar esteja visitando seja maior que o dado do usuário
    
    ant = aux; //Avança ant
    aux = aux->prox; //Avança aux
  }

  //Se o início for nulo, o novo nó será o início e o fim
  if (!lst->ini){
    lst->ini = lst->fim = novo;
  }

  //Se por acaso o dado precise ser inserido no início da lista
  else if (aux == lst->ini){
    novo->prox = lst->ini; //O sucesso do novo nó recebe o início da lista
    lst->ini = novo; //O início da lista recebe o novo nó
  } 

  //Se o dado precisa ser inserido no fim da lista (aux não nulo)
  else if (!aux){
    lst->fim->prox = novo; //O sucessor do fim da lista recebe o novo nó
    lst->fim = novo; //O fim da lista recebe o novo nó
  } 
  
  else { //Se o dado pecisa ser inserido no meio da lista
  ant->prox = novo; //O sucesso de anterior recebe o novo nó
  novo->prox = aux; //O sucessor do novo nó recebe o atual auxiliar
  }
  
}

void remover(LISTA *lst, int dado) { 

  struct sNODE *aux = lst->ini; 
  struct sNODE *ant = NULL; 

  while (aux != NULL) { 

    if (aux->dado == dado) { 

      if (aux == lst->ini) { 
        lst->ini = aux->prox; 
      } 

      else if (aux == lst->fim) { 
        lst->fim = ant; 
        lst->fim->prox = NULL; 
      } 

      else {
        ant->prox = aux->prox; 
      }

      free(aux); 
      return;
    }

    //Caso não seja nada dos casos acima ele avança item a item
    ant = aux; 
    aux = aux->prox;  
  }
}

struct sNODE *buscar(LISTA *lst, int dado) { 
  
  struct sNODE *aux = lst->ini; 
  
  while (aux != NULL) { 
    if (aux->dado == dado) { 
      return aux; 
    }
    aux = aux->prox; 
  }
  return NULL; 
}

//Função obter: Você já sabe o nó que quer proucurar, então basta retornar o dado dele
int obter(struct sNODE *node) {

  if (!node){ 
    printf("Erro ao obter dado. Ponteiro invalido.");
    exit(0);
  }

  return node->dado; 
}

int tamanho(LISTA *lst) {

  int cont = 0; 

  struct sNODE *aux = lst->ini; 

  while (aux != NULL) { 
    cont++; 
    aux = aux->prox; 
  }

  return cont;
}

void imprimir(LISTA *lst) {
  struct sNODE *aux = lst->ini; 

  printf("[ "); 

  while (aux != NULL) { 
    
    printf("%d ", aux->dado); 
    aux = aux->prox; 
  }

  printf("]\n"); 
}