#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir(int elemento);
int buscar(int elemento);
void remover(int elemento);
int obter(int indice);
int tamanho();
void imprimir();
void apagar();
void inserirOLD(int elemento);

int buscar(int elemento){
  for (int i = 0 ; i < pos ; i++){
  if (l[i] == elemento)
    return i;
  }
  return -1;
}

void inserirOLD(int elemento){
  if (pos < MAX)
  l[pos++] = elemento;
  else {
  printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

void inserir(int elemento){

  if(buscar(elemento)!=-1){
    printf("Elemento %d já esta na lista. Encerrando...\n",elemento); 
    return;
  }
  
  else { if (pos < MAX){
        l[pos++] = elemento;
        }
        else {
        printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
        }
  }
}

void remover(int elemento){

  int count = 0; // Contador para o número de elementos removidos
  int refazendo = 0; // Índice para onde os elementos não alvos do remover serão movidos

  for (int i = 0; i < pos; i++) {
      if (l[i] != elemento) {
          //O que não for pra ser removido vai trazendo pro indice 0/1/2/3..., assim, refazendo a lista
          l[refazendo++] = l[i];
      } 
      else {count++;} 
  }

  pos -= count; // Atualiza a posição de acordo com os elementos removidos

  if (count == 0) {
    printf("Elemento %d não encontrado na lista.\n", elemento);
  } 
  else {
    printf("%d ocorrência(s) do elemento %d removida(s) da lista.\n", count, elemento);
  }
}

void imprimir(){
  if(pos==0){printf("lista vazia! \n");} //para ajudar na visualização
  else{
  for (int i = 0 ; i < pos ; i++)
  printf("%d ",l[i]);
  printf("\n");
  }
}

void apagar(){
  pos = 0;
}

int main(void) {

  printf("Criando lista com valores de 0-8:\n");
  for(int i = 0; i < MAX-1; i++){ //Deixando um espaço vago
    inserir(i);
  }
  imprimir();
  printf("\n");
  
  printf("Teste: Adicionando 9:\n");
  inserir(9);
  imprimir();
  printf("\n");
  
  printf("Teste: Inserindo o elemento 9 novamente:\n");
  inserir(9);
  printf("\n");
  
  printf("Limpando para realizar novos testes!!\n");
  apagar();
  imprimir();
  printf("\n");

  printf("Observação: Pode ser usada outra função (inserirOLD) que permite repetidos a partir de agora\n");
  printf("\n");
  printf("Teste: Adicionando vários 9:\n");
  for(int i = 0; i < MAX; i++){
    inserirOLD(9);
  }
  imprimir();
  printf("\n");
  
  printf("Teste: Qual índice buscar para 9 irá retornar?:\n");
  printf("%d\n",buscar(9));
  printf("\n");

  remover(9);
  printf("Teste: Removido todos os noves, o que sobrou na lista:\n");
  imprimir();
  printf("\n");

  
  printf("Limpando para realizar novos testes!!\n");
  apagar();
  imprimir();
  printf("\n");

  printf("Teste: Adicionando cinco 9's e cico 8's:\n");
  for(int i = 0; i<5; i++){inserirOLD(9);}
  for(int i = 5; i<10; i++){inserirOLD(8);}
  imprimir();
  printf("\n");

  printf("Teste: Qual índice buscar para 8 irá retornar?:\n");
  printf("%d\n",buscar(8));
  printf("\n");
  
  remover(9);
  printf("Teste: (NOVAMENTE) Removido todos os noves, o que sobrou na lista:\n");
  imprimir();
  printf("\n");
  
  return 0;
}