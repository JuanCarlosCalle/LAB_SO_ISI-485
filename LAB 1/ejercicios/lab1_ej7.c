//#include <iostream.h>
#include <conio.h> 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){ 
bool continuar,acerto; 
char opcion; 
unsigned int respuesta,numero1,numero2,resultado, 
cartel,contador=0,correctas=0; 
srand(time(NULL)); 
do{ 
continuar=true; 
acerto=false; 
numero1=1+rand()%9; 
numero2=1+rand()%9; 
resultado=numero1*numero2; 
while(acerto==false){ 
printf("How much is %d times %d? : ",numero1,numero2); 
scanf("%u",&respuesta); 
contador=contador+1; 
if(respuesta==resultado){ 
correctas=correctas+1; 
cartel=1+rand()%4; 
acerto=true;} 
else cartel=5+rand()%3; 
switch(cartel){ 
case 1:printf("MUY BIEN!"); 
break; 
case 2:printf("Excelente!"); 
break; 
case 3:printf("BUEN TRABAJO!"); 
break; 
case 4:printf("SIGUE INTENTADO!"); 
break; 
case 5:printf("No. TRATA OTRA VEZ."); 
break; 
case 6:printf("MAL , PRUEBA UNA VEZ  MAS."); 
break; 
case 7:printf("NO TE RINDAS!"); 
break; 
} 
printf("\n"); 
system("pause"); 
system("cls");}


printf("Desea continuar? presione la tecla S para proseguir o N para terminar: "); 
opcion=getch(); 
opcion=toupper(opcion); 
if(opcion=='S'){ 
continuar=false; 
system("cls");}} 
while(continuar==false); 
if(((correctas*100)/contador)<75) 
printf("\nPor favor, solicite ayuda adicional a su instructor."); 
getchar(); 
return 0;}
