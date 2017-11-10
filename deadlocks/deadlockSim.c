#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <signal.h>

#define SNAME "/commonMutex1"
#define SEM_NAME "/commonMutex2"


sem_t *g;

void leave(){	
	int p;
	sem_getvalue(g,&p);
	printf("\nReleasing Lock -> %d\n",p);
	sem_post(g);
	sem_getvalue(g,&p);
	printf("\nReleasing Lock -> %d\n",p);
	exit(0);

}

int main()
{

	signal(SIGINT, leave);
	
	sem_t *mutex1 = sem_open(SNAME, O_CREAT, 0644, 1); 

	g = mutex1;

	printf("Created Mut 1\n");

	sleep(2);


	sem_t *mutex2 = sem_open(SEM_NAME, 0); /* Open a preexisting semaphore. */

	printf("Opened Mut 2\n");

	sem_wait(mutex1);

	sleep(2);

	printf("Going to Accquire Mut 2\n");
	sem_wait(mutex2);

	printf("Done\n");
	sleep(2);

	sem_post(mutex2);
	sem_post(mutex1);


	return 0;
}


