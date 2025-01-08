#include <stdio.h>
#include <stdlib.h>

//Configura a estrutura do/s nó/s da lista
struct sNODE { //Configura uma variável do tipo struct chamada sNODE
  int dado; //Campo da struct do nó que receberá um dado 
  struct sNODE *prox; //Campo da struct do nó que serva para apontar para o sucessor do nó atual
};

//Cria os ponteiros globais "ini" e "fim" que podem apontar para a struct sNODE e determinar os limites iniciais e finais de uma lista
struct sNODE *ini = NULL, *fim = NULL; 

//Assinatura das funções que criam uma lista encadeada
void inserir_ini(int dado);                        //*
void inserir(int dado);                            //*
struct sNODE *buscar(int dado);                    //*
void remover(int dado);                            //*
void apagar();                                     //*
void imprimir();                                   //*
int obter(struct sNODE *node);                     //*
int tamanho();                                     //*
//Assinatura das funções que criam uma lista encadeada

//Main
int main(void) {

  printf("Lista com elementos originais:\n");
  //Teste com as funções:
  inserir(10); //Insere o elemento 10 na lista
  inserir(20); //Insere o elemento 20 na lista
  inserir(30); //Insere o elemento 30 na lista  
  inserir(40); //Insere o elemento 40 na lista
  inserir(50); //Insere o elemento 50 na lista
  inserir(50); //Insere o elemento 50 novamente na lista
  inserir(60); //Insere o elemento 60 na lista

  imprimir(); //Imprime a lista

  remover(50); //Remove o primeiro elemento 50 da lista

  printf("\nLista pós remoção de um 50: \n");
  imprimir(); //Imprime a lista

  printf("\nDados que os ponteiros ini e fim apontam: \n");
  printf("%d e %d\n",obter(ini),obter(fim));

  printf("\nTamanho da lista: \n");
  printf("%d elementos\n",tamanho());

  printf("\nApagando a lista... \n");
  apagar();

  printf("\nLista pós apagamento: \n");
  imprimir();
  
  printf("\nTamanho da lista: \n");
  printf("%d elementos\n",tamanho());

  inserir_ini(10);
  inserir_ini(20);
  inserir_ini(30);
  printf("\nLista pós inserir_ini de 10->20->30: \n");
  imprimir();
  
  return 0;
}

//Atividade 1:
void inserir_ini(int dado){
  struct sNODE *aux = (struct sNODE*) malloc(sizeof(struct sNODE));

  aux->dado = dado;
  aux->prox = ini; //O próximo do nó auxiliar aponta para o nó inicial

  if(ini == NULL){ //Se for inserir o dado mas a lista estiver vazia?
    ini = aux;
    fim = aux;
  }

  else{ //E se a lista não estiver vazia?
    ini = aux; //Nó inicial recebe o nó auxiliar atual
  }
}

//Função inserir: INSERE UM DADO AO FINAL DA LISTA
void inserir(int dado) { //Recebe o dado

  //Aloca dinamicamente um espaço na memória para um nó chamado aux
  struct sNODE *aux = malloc(sizeof(struct sNODE)); 
  //Malloc aloca 12 bytes. Sistema 64 bits: 4 bytes (int) + 8 bytes (ponteiro) = 12 bytes
  
  aux->dado = dado; //O campo "dado" da struct do nó "aux" apontará para o novo dado do usuário
  aux->prox = NULL; //Agora o próximo nó da lista apontará para o fim dela (NULL ou "terra")

  //Se for inserir o dado mas a lista estiver vazia?
  if (ini == NULL) { 
    ini = aux; //Então o dado que você está inserindo agora é o elemento inicial da lista
    fim = aux; //E também o elemento final, afinal a lista só tem 1 elemento agora.
  } 

  //E se a lista não estiver vazia?
  else {
    fim->prox = aux; //O elemento sucessor de fim (fim->prox), que era NULL (aterramento da lista), agora recebe o novo dado do usuário armazenado no campo "dado" da struct do nó "aux"
    
    fim = aux; //Por fim o elemento final da lista agora é o novo elemento inserido
  }
}

//Função buscar: BUSCA UM DADO NA LISTA E RETORNA O ENDEREÇO DO NÓ QUE ELE SE ENCONTRA
struct sNODE *buscar(int dado) { //Recebe o dado do usuário que será comparado ao campo "dado" do ponteiro ser procurado
  
  struct sNODE *aux = ini; //Cria poneteiro auxiliar que aponta para o inicio da lista
  
  while (aux != NULL) { //Enquando ponteiro auxiliar não apontar para o aterramento ou fim da lista
    
    if (aux->dado == dado) { //Se o campo "dado" do nó que o ponteiro auxiliar aponta for igual ao dado que o usuário inseriu então ele achou o ponteiro certo
      
      return aux; //Retorna o endereço do ponteiro do nó que o dado está
    }

    aux = aux->prox; //Avançando... Nó atual (aux) recebe o próximo nó da lista (aux->prox)
  }
  return NULL; //Se não encontrar o dado, retorna NULL.
}

//Função remover: REMOVE UM DADO DA LISTA
void remover(int dado) { //Recebe o dado a ser removido
  
  struct sNODE *aux = ini; //Cria ponteiro auxiliar que aponta para o inicio da lista
  
  struct sNODE *ant = NULL; //Cria ponteiro anterior que aponta para nada mas que pode ser interpretado como o elemento anterior ao início
  
  while (aux != NULL) { //Enquando ponteiro auxiliar não apontar para o aterramento ou fim da lista
      
    if (aux->dado == dado) { //Caso o campo "dado" do nó que o ponteiro auxiliar aponta for igual ao dado inserido pelo usuário
      
      if (aux == ini) { //E caso o nó que o ponteiro auxiliar aponta seja o início da lista
        ini = aux->prox; //Início da lista agora apontará para o próximo nó da lista
      } 
      
      else if (aux == fim) { //Mas se o nó que o ponteiro auxiliar aponta for o fim da lista
        fim = ant; //Fim da lista agora recebe o elemento anterior a fim já que queremos remover o elemento final
        fim->prox = NULL; //O próximo nó do elemento final agora é o aterramento da lista
      } 
      
      else { //Mas se o nó que o ponteiro auxiliar aponta não for o início nem o fim, ou seja, estiver no meio da lista
        ant->prox = aux->prox; //O próximo elemento do anterior agora recebe o sucessor do elemento do nó que o ponteiro auxiliar aponta (aux está logo depois de anterior)
      }
      
      free(aux); //Libera o espaço de memória do nó que o ponteiro auxiliar aponta (elemento que queremos remover)
      return;
    }

    //Caso não seja nada dos casos acima ele avança item a item
    ant = aux; //Nó anterior (ant) recebe nó atual (aux)
    aux = aux->prox; //Avançando... Nó atual (aux) recebe o próximo nó da lista (aux->prox)
  }
}

//Função apagar: APAGA TODA A LISTA
void apagar() {
  struct sNODE *aux = ini; //Cria variável auxiliar que aponta para o inicio da lista
  struct sNODE *ant = NULL; //Cria variável anterior que aponta para nada mas que pode ser interpretado como o elemento anterior ao ini

  //Enquanto aux avança o anterior à aux vai sendo apagado
  while (aux != NULL) { 
    ant = aux; //Nó anterior (ant) recebe nó atual (aux)
    aux = aux->prox; //Avançando... Nó atual (aux) recebe o próximo nó da lista (aux->prox)
    free(ant); //Libera o espaço de memória alocado do nó anterior (ant)
  }
  ini = fim = NULL; // Atualizando elementos da lista já que tudo foi apagado e não existe mais referência de começou ou fim
}

//Fução imprimir: IMPRIME A LISTA INTEIRA
void imprimir() {
  struct sNODE *aux = ini; //Cria variável auxiliar que aponta para o inicio da lista

  printf("[ "); //Elemento estético para o início print

  while (aux != NULL) { //Enquando ponteiro auxiliar não apontar para o aterramento ou fim da lista
    
    printf("%d ", aux->dado); //Imprima o campo "dado" do nó que o ponteiro auxiliar aponta
    aux = aux->prox; //Avançando... Nó atual (aux) recebe o próximo nó da lista (aux->prox)
  }

  printf("]\n"); //Elemento estético para o final do print
}

//Função obter: RETORNA O DADO DE UM NÓ QUE O USUÁRIO DESEJA
int obter(struct sNODE *node) {

  //Se o ponteiro node é NULL
  if (!node){ //Se node for NULL, !node será verdadeiro, e o corpo do if será executado.
    
    //NULL indica que o ponteiro não aponta para nenhum endereço de memória válido, ou seja, ele é "inválido".
    
    printf("Erro ao obter dado. Ponteiro invalido.");
    exit(0);
  }
  
  return node->dado; //Se o ponteiro for válido, retorna o que está no campo "dado" do nó que o usuário inseriu
}

//Função tamanho: RETORNA O TAMANHO DA LISTA
int tamanho() {

  int cont = 0; //Cria variável contadora
  
  struct sNODE *aux = ini; //Cria variável auxiliar que aponta para o inicio da lista
  
  while (aux != NULL) { //Enquando ponteiro auxiliar não apontar para o aterramento ou fim da lista
    cont++; //Incrementa o contador
    aux = aux->prox; //Avançando... Nó atual (aux) recebe o próximo nó da lista
  }

  return cont; //Retorna o tamanho da lista
  
}