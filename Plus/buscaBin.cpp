#include <stdio.h>
#include <stdlib.h>

int buscaBin(int l[], int tam, int num) {
  int ini = 0, fim = tam -1;
  int meio = (ini + fim) / 2;

  while (ini <= fim) {
    if (l[meio] == num)
      return meio;
    else {
      if (num < l[meio])
        fim = meio - 1;
      else
        ini = meio + 1;
      meio = (ini + fim) / 2;
    }
  }
  return -1;
}

int main(){
  int l[] = {1,3,5,7,9,11}, tam = 6;
  
  printf("Achei 3 em %d \n",buscaBin(l, tam, 3));
  printf("Achei 9 em %d \n",buscaBin(l, tam, 9));
  
  return 0;
}

