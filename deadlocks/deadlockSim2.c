#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */


#define SNAME "/commonMutex2"
#define SEM_NAME "/commonMutex1"



int main()
{
	
	sem_t *mutex1 = sem_open(SNAME, O_CREAT, 0644, 1); 

	printf("Created Mut 2\n");

	sleep(2);


	sem_t *mutex2 = sem_open(SEM_NAME, 0); /* Open a preexisting semaphore. */

	printf("Opened Mut 1\n");

	sem_wait(mutex1);


	printf("Going to Accquire Mut 1\n");
	
	sleep(2);
	sem_wait(mutex2);

	printf("Done\n");

	sleep(2);

	sem_post(mutex2);
	sem_post(mutex1);

	

	return 0;
}


