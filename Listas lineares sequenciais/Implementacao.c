#include <stdio.h>
const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir_ord(int elemento);

void inserir(int elemento);
int buscar(int elemento);
void remover(int elemento);
int obter(int indice);
int tamanho();
int imprimir();
void apagar();

/*
int main(void) {
  inserir(1);
  inserir(2);

  printf("Buscando 1 => %d\n",buscar(2));
  printf("Buscando 1 => %d\n",buscar(5));

  inserir(100);

  inserir(200);

  imprimir();

  remover(100);

  imprimir();

  apagar();

  imprimir();

  return 0;
}
*/

int main(void) {
  inserir_ord(10);
  inserir_ord(20);
  inserir_ord(30);
  inserir_ord(40);

  inserir_ord(22);

  imprimir();


  return 0;
}
void inserir_ord(int elemento)
{
  if (pos >= MAX)
  {
    printf("Lista cheia!\n");
    return;
  }

  //1 - encontrar a pos
  int p = 0;
  while ( p < pos && l[p] < elemento)
    p++;

  //2 - fazer arrastao
  for (int i = pos ; i > p ; i--)
    l[i] = l[i-1];

  //3 - inserir o elemento
  l[p] = elemento;
  pos++;
}


void inserir(int elemento)
{
  if (pos < MAX) {
    l[pos] = elemento;
    pos++;
  } else
    printf("Lista cheia!!\n");
}

void inserir2(int elemento)
{
  if (pos >= MAX)
    printf("Lista cheia!!\n");
  else
  {
    l[pos] = elemento;
    pos++;
  }
}

void inserir3(int elemento)
{
  if (pos >= MAX)
    printf("Lista cheia!!\n");
  else
    l[pos++] = elemento;
}

void inserir4(int elemento)
{
  if (pos < MAX) l[pos++] = elemento;
}

int buscar(int elemento)
{
  for (int i = 0 ; i < pos ; i++)
    if (l[i] == elemento)
      return i;

  return -1;
}

void remover(int elemento)
{
  int r = buscar(elemento);

  if (r!=-1)
  {
    for (int i = r ; i < pos - 1 ; i++)
      l[i] = l[i+1];
    pos--;
  }
}

void remover2(int elemento)
{
  for (int r = 0 ; r < pos ; r++)
    if (l[r] == elemento)
    {
      for (int i = r ; i < pos - 1 ; i++)
        l[i] = l[i+1];
      pos--;
      break;
    }
}

int obter(int indice)
{
  if (indice >= 0 && indice < pos)
    return l[indice];
  else
  {
    printf("Indice inexistente!\n");
    return 0;
  }
}

int tamanho()
{
  return pos;
}

int imprimir()
{
  printf("[ ");
  for (int i = 0 ; i < pos ; i++)
    printf("%d ",l[i]);
  printf("]\n");
}

void apagar()
{
  pos = 0;
}