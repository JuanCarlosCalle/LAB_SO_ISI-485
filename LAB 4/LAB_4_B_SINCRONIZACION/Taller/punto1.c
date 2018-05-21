// Ejercicio fue tomado de: http://stackoverflow.com/questions/21844350/sleeping-barber-using-semaphore
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


// Se define el numero maximo de hilos clientes
#define MAX_CUSTOMERS 25

// Se definen las funciones que realizan los clientes y el barbero
void *customer(void *num);
void *barber(void *);
// Se define una funcion adicional que hace esperar el hilo por un tiempo
void randwait(int secs);

// Ahora, se procede a crear los semaforos

// Este semaforo limita el numero de clientes permitidos para entrar a la sala de espera uno a la vez
sem_t waitingRoom;   

// Semaforo para garantizar mutuamente el acceso exclusivo (turno) a la silla del barbero
sem_t barberChair;

// Semaforo que es usado para permitir que el barbero duerma hasta que algun cliente llegue
sem_t barberPillow;

// Semaforo usado para hacer el cliente esperar hasta que el barbero haya terminado de hacer el corte de pelo
sem_t seatBelt;

// Variable centinela que uso para detener el hilo del barbero una vez que todos los clientes ya han sido atendidos
int allDone = 0;

int main(int argc, char *argv[])
{
    pthread_t btid; // Creo un hilo para el barbero
    pthread_t tid[MAX_CUSTOMERS]; // Creo tantos hilos como numero maximo de ellos se haya definido
    long RandSeed; // Variable para manejar una semilla aleatoria
    // Variables para iterar entre los hilos clientes y las sillas de espera
    int i, numCustomers, numChairs;
    // Arreglo para saber el orden de atencion
    int Number[MAX_CUSTOMERS];

    // Antes de seguir reviso que el numero de argumentos del programa sea correcto, sino entonces
    if (argc != 4)
    {
        // Imprimo un mensaje y termino
        printf("Los parametros deben ser: ./ejecutable <Numero de clientes> <Numero de sillas de espera> <Semilla aleatoria\n");
        exit(-1);
    }

    // Si los argumentos son correctos entonces los recupero
    numCustomers = atoi(argv[1]);
    numChairs = atoi(argv[2]);
    RandSeed = atol(argv[3]);

    // En caso que el numero de clientes deseados por el usuario es mayor a los que puede manejar el programa entonces
    if (numCustomers > MAX_CUSTOMERS)
    {
        // Imprimo un mensaje y termino
        printf("El maximo numero de clientes es %d.\n", MAX_CUSTOMERS);
        exit(-1);
    }

    // Luego imprimo un mensaje indicando que el programa comienza
    printf("\nBarbero Dormilon\n");
    printf("Una solucion al problema del barbero dormilon usando semaforos\n\n");

    // Ahora, en primer lugar inicializamos el proceso de aleatorizacion a partir de la semilla dada por el usuario
    srand48(RandSeed);

    // Despues se inicializa el vector de numeros
    for (i=0; i<MAX_CUSTOMERS; i++)
    {
        Number[i] = i;
    }

    // Se inicializan los semaforos con sus valores iniciales
    sem_init(&waitingRoom, 0, numChairs);
    sem_init(&barberChair, 0, 1);
    sem_init(&barberPillow, 0, 0);
    sem_init(&seatBelt, 0, 0);

    // A continuacion, se crea el hilo del barbero
    pthread_create(&btid, NULL, barber, NULL);

    // Y tambien se crean los hilos de los clientes
    for (i=0; i<numCustomers; i++)
    {
        pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
    }

    // Ya con los hilos clientes creados se espera por la finalizacion (atencion) de los mismos
    for (i=0; i<numCustomers; i++)
    {
        pthread_join(tid[i],NULL);
    }

    // Una vez se atendieron todos los clientes se procede a terminar el hilo del barbero (O sea, se levanta la variable centinela)
    allDone = 1;

    // Y se despierta el barbero para que este pueda irse
    sem_post(&barberPillow); 
    pthread_join(btid,NULL);

    return 0;
}

void *customer(void *number)
{
    int num = *(int *)number;

    // El cliente parte hacia la barberia y le toma un tiempo (aleatorio) en llegar a la misma.
    printf("Cliente %d parte a la barberia.\n", num);
    randwait(5);
    printf("Cliente %d llega a la barberia.\n", num);

    // El espera a que algun cliente desocupe una silla del salon de espera
    sem_wait(&waitingRoom);
    printf("Cliente %d entro a la sala de espera.\n", num);

    // El espera a que el babero se desocupe y su silla este libre
    sem_wait(&barberChair);

    // Luego, cede su silla en el salon de espera
    sem_post(&waitingRoom);

    // Despierta el barbero
    printf("Cliente %d despierta el barbero\n", num);
    sem_post(&barberPillow);

    // Espera a que el barbero termine el corte
    sem_wait(&seatBelt);

    // Y cede la silla del barbero
    sem_post(&barberChair);
    printf("Cliente %d deja la barberia.\n", num);

    return NULL;
}

void *barber(void *junk)
{
    // Mientras existan clientes que piensen en ir a la barberia
    // El barbero telepaticamente sabra si hay clientes que van a ir y esperara
    while (!allDone)
    {
        // Mientras el barbero dormira hasta que un cliente llegue y lo despierte
        printf("El barbero esta durmiendo...\n");
        sem_wait(&barberPillow);

        // De este modo, si hay clientes por atender entonces
        if (!allDone)
        {
            // El barbero comenzara hacer los cortes de cada cliente
            printf("El barbero esta haciendo el corte...\n");
            randwait(3);
            printf("El barbero termino el corte.\n");

            // Una vez termina con el cliente llama al siguiente
            sem_post(&seatBelt);
        }
        else // sino
        {
            printf("El barbero se va hacia su casa.\n");
        }
    }

    return NULL;
}

void randwait(int secs)
{
    int len;

    // Se genera un numero aleatorio...
    len = (int) ((drand48() * secs) + 1);
    sleep(len);
}
