#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define T_COUNT 10
#define L_COUNT 5

sem_t mutex,licence;

int valT[T_COUNT];
int lic[L_COUNT];


void keepRecource(int i){

	sem_wait(&mutex);

	printf("\n %d Thread is requesting Licence\n", i);

	sem_wait(&licence);

	printf("\n %d Thread is using Licence\n", i);

	sem_post(&mutex);

	

}

void leaveResource(int i){

	sem_wait(&mutex);

	printf("\n %d Thread is leaving Licence\n", i);

	sem_post(&licence);

	printf("\n %d Thread left the Licence\n", i);

	sem_post(&mutex);

}

void *initThread(void* arg){

	int *u = arg;

	while(1){

		keepRecource(*u);

		sleep(1);

		leaveResource(*u);
	}

}


int main()
{	

	sem_init(&mutex , 0, 1);

	sem_init(&licence , 0, L_COUNT);

	pthread_t t[T_COUNT];

	int i;

	for ( i = 0; i < T_COUNT; ++i)
	{	
		valT[i] = i;
		pthread_create(&t[i], NULL , initThread , &valT[i]);
	}

	for ( i = 0; i < T_COUNT; ++i)
	{
		pthread_join(t[i], NULL);
	}
	
	return 0;
}