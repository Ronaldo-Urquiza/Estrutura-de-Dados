#include <stdio.h>
#include <stdlib.h>

typedef struct { //Entendi isso aqui, uma struct para manejar cada lista 
 unsigned MAX; //tamanho da determinada lista
 int *arr, pos; //arr é o vetor que armazena os elementos da lista e pos é a posição desses elemtentos no vetor
} LISTA; //criei uma variável  do tipo LISTA e posso chamar LISTA x

void criar(LISTA *lst, int tam_MAX);

void inserir_ord(LISTA *lst, int elemento);
void remover(LISTA *lst, int elemento);
int buscar(LISTA *lst, int elemento);

int obter(LISTA *lst, int indice);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);

void criar(LISTA *lst, int tam_MAX){

  lst->MAX = tam_MAX; //vc vai passar o tamanho máximo da lista
  lst->pos = 0; //a posição fica definido em 0 ja q ela acabou d ser criada

  //o array da LISTA recebe
  //       conversão de ponteiro          tamanho de bytes do int   qtde para alocar
  lst->arr =       (int*)        malloc(       sizeof(int)     *  lst->MAX);
  
  //1º convertendo o ponteiro retornado por malloc() para um ponteiro de tipo int*

  //2º alocando o espaço de memória para o array da LISTA com malloc()

  //3º o espaço de memória é 4 bytes (sistema 32 bits) ou 8 bytes (sistema 64 bits) * MAX
  
  if (lst->arr == NULL){ //Se a memória não foi alocada... 
                         //Malloc retorna NULL quando não consegue alocar
    printf("ERRO FATAL! Memoria nao pode ser alocada.\n"); //avisa 
    exit(1); //finaliza o programa com saída de erro
  } 
  
} //Função criar pronta

//Passo 1: adaptar cabeçalho ok

void inserir_ord(LISTA *lst, int elemento){
  int i, p;
  if (lst->pos < lst->MAX) {
  for (i = 0 ; i < lst->pos ; i++)
        if (lst->arr[i] >= elemento)
              break;

  for (p = lst->pos ; p > i ; p--)
    lst->arr[p] = lst->arr[p-1];

  lst->arr[i] = elemento;

  lst->pos ++;
  }
  else {
  printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
} //Função inserir_ord pronta

int buscar(LISTA *lst, int elemento){
  for (int i = 0 ; i < lst->pos ; i++){
  if (lst->arr[i] == elemento)
    return i;
  }
  return -1;
} //Função buscar pronta

void remover(LISTA *lst, int elemento){
  int p = buscar(lst, elemento);

  if (p == -1)
  return;

  for (int i = p ; i < lst->pos -1; i++)
  lst->arr[i] = lst->arr[i+1];
  lst->pos--;
} //Função remover pronta

int obter(LISTA *lst, int indice){
  if (indice < 0 || indice >= lst->pos) {
  printf("Indice %d fora dos limites da Lista.\n", indice);
  exit(1);
  }
  return lst->arr[indice];
} //Função obter pronta

int tamanho(LISTA *lst){ 
  return lst->pos;
} //Função tamanho pronta

void imprimir(LISTA *lst){
  if(lst->arr==NULL){printf("Lista(s) Vazia(s)!\n");}
  for (int i = 0 ; i < lst->pos ; i++)
  printf("%d ", lst->arr[i]);
  printf("\n");
} //Função imprimir pronta

void apagar(LISTA *lst){
  free(lst->arr); //liberando memoria alocada
  lst->arr = NULL; //limpando ponteiro
} //Função apagar pronta

int main(void) {
  LISTA l1, l2; //criando 2 variaveis do tipo LISTA (structs)
  
  criar(&l1,10);
  criar(&l2,20);

  inserir_ord(&l1,10);
  inserir_ord(&l1,20);
  inserir_ord(&l1,15);

  inserir_ord(&l2,30);
  inserir_ord(&l2,40);
  inserir_ord(&l2,45);

  printf("Lista 1: (Inserção com ordenamento) \n");
  imprimir(&l1);
  printf("\n");

  printf("Lista 2: (Inserção com ordenamento)\n");
  imprimir(&l2);
  printf("\n");

  printf("Operações com lista 1: \n");
  printf("\n");
  
  printf("Buscar elemento (elemento 20): %d\n", buscar(&l1,20));
  printf("Obter elemento (indice 2): %d\n", obter(&l1,2));
  printf("Tamanho da lista 1: %d\n", tamanho(&l1));
  printf("Remover elemento 20: \n");
  remover(&l1,20);
  printf("Lista 1 -> ");imprimir(&l1);
  printf("\n");

  printf("\n");
  
  printf("Operações com lista 2: \n");
  printf("\n");

  printf("Buscar elemento (elemento 45): %d\n", buscar(&l2,45));
  printf("Obter elemento (indice 2): %d\n", obter(&l2,2));
  printf("Tamanho da lista 2: %d\n", tamanho(&l2));
  printf("Remover elemento 40: \n");
  remover(&l2,40);
  printf("Lista 2 -> ");imprimir(&l2);
  
  apagar(&l1);
  apagar(&l2);

  printf("\n");
  printf("Teste, apagando listas e imprimindo lista 1 e lista 2: \n");
  imprimir(&l1);
  imprimir(&l2);
  
  return 0;
}