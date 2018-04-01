#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiplo(int,int);

int main (int argc,char *argv[])

{
	int numuno;
	int numdos;

	printf("\n Este programa recibe dos numeros y le dice si ");
	printf("son o no multiplos.\n ");
	
	printf("Digite primer numero :");
	scanf("%d",&numuno);
	
	printf("Digite segundo numero :");
	scanf("%d",&numdos);
	
	int resultado;
	resultado=multiplo(numuno,numdos);
	printf("%d",resultado);
	
	return 0;
}

int multiplo(int numuno , int numdos){
	if(numuno%numdos==0){
		return 1;
	}else{
		return 0;
	}
	
	
}
