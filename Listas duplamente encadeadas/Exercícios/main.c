#include <stdio.h>
#include <stdlib.h>

struct sNODE {
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL; 

void inserir_ini(int dado);
void imprimir_reverso();

void imprimir();
void remover(int dado);
struct sNODE *buscar(int dado);
int obter(struct sNODE *node);
int tamanho();
void apagar();

int main(void) {
  inserir_ini(30); //Tem que ser o último
  inserir_ini(20); //Tem que ser o penúltimo
  inserir_ini(10); //Tem que ser o primeiro
  
  printf("Lista impressa normalmente: ");
  imprimir();
  
  printf("\n");
  
  printf("Lista impressa reversamente: ");
  imprimir_reverso();
  
  return 0;
}

void inserir_ini(int dado) { 
  struct sNODE *no = (struct sNODE *) malloc(sizeof(struct sNODE)); 

  no->dado = dado;
  no->ant = NULL; // Como é o primeiro nó, seu ponteiro anterior é NULL
  
  if (ini == NULL) {

    ini = fim = no;
  } 
  
  else {
    ini->ant = no;  // Atualiza o ponteiro 'ant' do antigo nó inicial
    no->prox = ini;
    ini = no; // O ini é atualizado com novo valor
  }
  
}

void imprimir_reverso() {
  // com espaço entre os elementos
  struct sNODE *aux = fim;
  printf("[ ");
  while (aux != NULL) {
    printf("%d ", aux->dado);
    aux = aux->ant;
  }
  printf("]\n");
}

void imprimir() {
  // com espaço entre os elementos
  struct sNODE *aux = ini;
  printf("[ ");
  while (aux != NULL) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

struct sNODE *buscar(int dado) {
  struct sNODE *aux = ini;
  while (aux != NULL) {
    if (aux->dado == dado)
      return aux;
    aux = aux->prox;
  }
  return NULL;
}

void remover(int dado) {
  struct sNODE *aux = buscar(dado);
  if (aux == NULL)
    return;

  if (ini == fim) {
    ini = fim = NULL;
  } else if (aux == ini) {
    ini = ini->prox;
    ini->ant = NULL;
  } else if (aux == fim) {
    fim = fim->ant;
    fim->prox = NULL;
  } else {
    // (*(*aux).ant).prox = (*aux).prox;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
  }
  free(aux);
}

int obter(struct sNODE *node) {
  if (node != NULL)
    return node->dado;  
  exit(1);
}

int tamanho() {
  struct sNODE *aux = ini;
  int contador = 0;
  while (aux != NULL) {
    contador++;
    aux = aux->prox;  
  }
  return contador;
}

void apagar() {
  struct sNODE *aux = ini, *ant = NULL;
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
}

