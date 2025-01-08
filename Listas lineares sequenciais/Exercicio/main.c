#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

//Declarando funções 
void inserir(int elemento);
void imprimir();
void inseririni(int elemento);

//Construindo funções
void inseririni(int elemento){
  if (pos < MAX) {    //verifica pra ver se n excedeu o limite
    
    //printf("pos: %d\n",pos); //testando pos

    //Começou em 9 por causa da função inserir(); que incrementa pos
    
    for (int i = pos; i > 0; i--) { //loop de trás para frente i=9/8/7/6/5/4/3/2/1
      //printf("i: %d\n",i); testando comportamento do i
      l[i] = l[i - 1];
    }
    
    l[0] = elemento;
    pos++;
  } 
    
  else{printf("Lista cheia!!\n");}

}

void inserir(int elemento){

  if (pos < MAX) {
    l[pos] = elemento;
    pos++;
  } else
    printf("Lista cheia!!\n");
}

void imprimir(){
  for (int i = 0 ; i < pos ; i++)
  printf("%d ",l[i]);
  printf("\n");
}

//Fim da biblioetca de listas
int main(void) {

  printf("Criando lista com valores de 0-8:\n");
  for(int i = 0; i < MAX-1; i++){ //Deixando um espaço vago
    inserir(i);
  }
  imprimir();

  printf("\n");
  printf("Teste: Incremento com lista com uma vaga:\n");

  inseririni(1);
  imprimir();

  printf("\n");
  printf("Teste: Incremento com lista cheia:\n");
  
  inseririni(1);

  return 0;
}
