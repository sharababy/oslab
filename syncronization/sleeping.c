#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define S_COUNT 10
#define MAX 4

#define RED     "\033[31m" 
#define RESET   "\033[0m"


int students;
int valT[S_COUNT];


sem_t mutex,student,studentDone,ta,taDone;


void * enterStudent(void * args){

	int *u = args;

	sem_wait(&mutex);

	if (students == MAX)
	{
		printf(RED"\nStudents Limit reached !\n");
		printf(RESET"\n");
		sem_post(&mutex);
		pthread_exit();	
	}

	printf("\nStudent %d Enters\n",*u);

	students++;

	sem_post(&mutex);

	printf("\nStudent %d Waits\n",*u);

	sem_post(&student);
	sem_wait(&ta);

	printf("\nStudent %d is Asking Doubt\n",*u);

	sleep(1);  // ask doubt

	sem_post(&studentDone);
	sem_wait(&taDone);

	printf("\nStudent %d Finished asking doubt\n",*u);

	pthread_exit();	
}


void * taAct(){

	// customer.wait() 
	// barber.signal()
	// # cutHair ()
	// customerDone.wait() 
	// barberDone.signal() 

	
	sem_wait(&student);
	sem_post(&ta)

	printf("\nTA is clearing doubt\n");
	sleep(1) // clear doubt

	sem_wait(studentDone);
	sem_post(taDone);

	pthread_exit();
}

int main()
{
		
	students = MAX;

	sem_init(&mutex , 0, 1);

	sem_init(&student , 0, 0);
	sem_init(&studentDone , 0, 0);
	sem_init(&ta , 0, 0);
	sem_init(&taDone , 0, 0);



	pthread_t t[S_COUNT];

	int i;
	int ex = 1;
	pthread_create(&t[0], NULL , initThread , NULL);
	pthread_create(&t[1], NULL , enterStudent , &ex);

	for ( i = 2; i < S_COUNT; ++i)
	{	
		valT[i] = i;
		pthread_create(&t[i], NULL , enterStudent , &valT[i]);
	}

	for ( i = 0; i < S_COUNT; ++i)
	{
		pthread_join(t[i], NULL);
	}



	return 0;
}
