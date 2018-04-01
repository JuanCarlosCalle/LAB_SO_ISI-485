#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () { 
  int N, M, cant, i, aleatorio;
  printf("Digite la cantidad de números que desea generar: ");
  scanf("%d",&cant);
  printf("Digite los limites (primero el superior, luego el inferior): ");
  scanf("%d%d",&N,&M);
  srand(time(NULL)); // nos devuelve un número entero aleatorio entre 0 y el RAND_MAX (un número enorme, como de 2 mil millones). 
  for(i = 0; i < cant; i ++) { 
    aleatorio = rand()%(N-M+1)+M; //Genera un numero entre M y N
    printf("%d ", aleatorio);
  } 
  printf("\n", aleatorio);
  system("PAUSE");
  return 0;
}

