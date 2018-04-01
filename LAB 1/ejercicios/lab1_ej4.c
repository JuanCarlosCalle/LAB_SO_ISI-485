#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define atoa(x) #x

int inverso(long);

int main (int argc,char *argv[])

{
	long numuno;
	

	printf("\n Este programa   ");
	printf("devuelva el número con sus dígitos en reversa.\n ");
	
	printf("Digite  numero :");
	scanf("%d",&numuno);
	
	
	
	
	inverso(numuno);
	
	
	
	return 0;
}

int inverso(long numuno){
	int digito; 
	printf( " Su numeral invertido es: " );
	while( numuno > 0 ) { 
	digito = numuno % 10; 
	numuno /= 10; 	 
	printf( "%d", digito ); 
	} 
	
}
