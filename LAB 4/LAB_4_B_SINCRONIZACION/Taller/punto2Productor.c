#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sched.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 10    // tamaño del buffer
#define CICLOS 10 // numero de ciclos de ejecución

int buffer[BUFFER_SIZE];
sem_t *sem_cont, *sem_free; // declaramos un puntero para el identificador de los semaforos

int main (int argc, char *argv[])
{
 int i;
 pid_t hijo;
 int val;
 int entrada, salida;    // índices a las zonas de insercion y extraccion del buffer

 entrada = salida = 0; // inicializacion

 printf("Creando semaforos .....\n");

 /* comprueba si ya existe el semaforo del contador de productos sino lo crea inicializado(0)*/
 if((sem_cont = sem_open("/sem_cont", O_CREAT, 0644, 0)) == (sem_t *)-1)
 {
   perror("Error creando semaforo 1");
 }

 /* comprueba si ya existe el semaforo del espacio libre y sino lo crea inicializado (BUFFER_SIZE)*/
 if((sem_free = sem_open("/sem_free", O_CREAT, 0644, BUFFER_SIZE)) == (sem_t *)-1)
 {
   perror("Error creando semaforo 2");
 }

 printf("Creando proceso hijo .....\n");

 hijo = fork() ;

 if (hijo == -1)
 {
   printf("error creando proceso hijo\n");

   sem_unlink("/sem_cont");
   sem_unlink("/sem_free");

   exit(0);
 }
 else if (hijo == 0)
 {
   /*estamos en el padre-> productor */
   printf("Soy el padre (productor) con PID:%d\n", getpid());
   sleep(1);

   for (i = 0; i <= CICLOS; i++)
   {
     sem_wait(sem_free); /* espera que haya espacio en el buffer y decrementa */
     buffer[entrada] = i; // produce un elemento
     entrada = (entrada + 1) % BUFFER_SIZE; // buffer circular

     // Una forma de hacer el interbloqueo es que el productor nunca avise cuando se ingreso un elemento en el buffer
     //sem_post(sem_cont); /* incrementa el contador del semáforo */


     sem_getvalue(sem_cont, &val); // valor del contador del semáforo
     printf("Soy el Productor: entrada=%d, Estado %d productos\n", entrada, val);
     sleep(1);
   }

   /* libero semáforos */
   sem_close(sem_cont);
   sem_close(sem_free);

   exit(0);
 }

 printf("Soy el padre espero que termine el hijo .....\n");

 wait(0); /* Esperar que acabe el hijo */

 printf("Soy el padre destruyo los semaforos y termino.....\n");

 sem_unlink("/sem_cont");
 sem_unlink("/sem_free");

 exit(0);
}
