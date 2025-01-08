#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;


void inserir_ini(FILA *fi, int dado);
void inserir_fim(FILA *fi, int dado);

int remover_ini(FILA *fi, int dado);
int remover_fim(FILA *fi, int dado);


void criar(FILA *fi);
void apagar(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
  FILA fila1;
  criar(&fila1);

  imprimir(&fila1);

  enqueue(&fila1, 100);
  enqueue(&fila1, 50);
  enqueue(&fila1, 200);

  imprimir(&fila1);

  printf("Dequeue do elemento: -> %d\n",dequeue(&fila1));

  imprimir(&fila1);

  apagar(&fila1);

  return 0;
}

void criar(FILA *fi){
  fi->ini = fi->fim = NULL;
}



void inserir_ini(FILA *fi, int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;
  novo->ant = NULL;

  if (!fi->ini)
    fi->ini = fi->fim = novo;
  else{
    fi->ini->prox = novo;
    novo->ant = fi->ini;
    fi->ini = novo;
  }
}

void inserir_fim(FILA *fi, int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;
  novo->ant = NULL;

  if (!fi->ini)
    fi->ini = fi->fim = novo;
  else{
    fi->fim->prox = novo;
    novo->ant = fi->fim;
    fi->fim = novo;
  }
}

int remover_ini(FILA *fi, int dado){
  
  //salvar aux
  struct sNODE *aux = fi->ini;
  //avançar ini pra prox
  fi->ini = fi->ini->prox;
  //se prox for um nó e nao nulo
  
  if (fi->ini){
    //atualiza ant
    fi->ini->ant = NULL;
    
    //free no aux
    free(aux);

    //retornar dado
    return dado;
  }
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

int remover_fim(FILA *fi, int dado){
  
}













void apagar(FILA *fi){
  struct sNODE *aux = fi->ini, *ant = NULL;

  while (aux){
  ant = aux;
  aux = aux->prox;
  free(ant);
  }
  fi->ini = fi->fim = NULL;
}


int tamanho(FILA *fi){
  struct sNODE *aux = fi->ini;
  int tam = 0;

  while (aux){
  tam++;
  aux = aux->prox;
  }

  return tam;
}

void imprimir(FILA *fi){
  struct sNODE *aux = fi->ini;

  printf("F[ ");
  while (aux){
  printf("%d ", aux->dado);
  aux = aux->prox;
  }
  printf("]\n");
}

