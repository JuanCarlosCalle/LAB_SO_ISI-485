#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void abinario(int n);

int main (int argc,char *argv[])

{
	int numuno;
	

	printf("\n Este programa recibe un numero lo convierte a binario");
	printf("si el numero es positivo.\n ");	
	do{
	printf("Digite numero numero :");
	scanf("%d",&numuno);
	printf("\n numero en binario:");	
	}while(numuno<0);	
	abinario(numuno);
	return 0;
}

void abinario(int n ){
if(n>1)abinario(n/2);

printf("%i",n%2);

	
}
