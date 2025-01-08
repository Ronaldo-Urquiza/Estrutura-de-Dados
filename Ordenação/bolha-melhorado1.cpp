#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int l[], int tam){
  for (int i = 0 ; i < tam ; i++)
    for (int j = 0 ; j < tam - 1 - i; j++)
      if (l[j] > l[j+1])
        troca(&l[j],&l[j+1]);
}

int main(void) {
  int l[] = {5,4,3,2,1}, tam = 5;

  bubbleSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l[i]);
  return 0;
}


