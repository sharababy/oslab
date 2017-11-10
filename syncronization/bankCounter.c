#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define C_COUNT 10

#define RED     "\033[31m"
#define GREEN	"\033[32m" 
#define RESET   "\033[0m"


int balance[C_COUNT], val[C_COUNT], globalBal, globalMinBal;

sem_t counter,mutex;


void* transact(void * arg){

	int *u = arg;

	printf("%d customer is Entered for a counter \n", *u);

	sleep(1);
	sem_wait(&counter);

	printf(GREEN"%d customer got a Counter\n", *u );
	printf(RESET"\n");
	sleep(1);

	int transactionType = rand()%2;

	if (transactionType == 0)
	{
		// credit

		sem_wait(&mutex);

		int amt = rand()%1000;

		balance[*u] += amt;

		globalBal += amt;

		printf("\nCredited from %d cutomer Acc | Balance = %d | Amt = %d | Global Bal = %d \n", *u , balance[*u] , amt , globalBal);

		sem_post(&mutex);

		// credit
	}

	else if(transactionType == 1){

		// debit

		sem_wait(&mutex);

		int amt = rand()%1000;

		if ((balance[*u]-amt) <= 100 || (globalBal-amt) <= globalMinBal)
		{
			printf(RED"\nCannot debit from %d cutomer Acc | Balance = %d | Amt = %d | Global Bal = %d \n", *u , balance[*u] , amt , globalBal);
			printf(RESET"\n");
		}
		else{

			balance[*u] -= amt;

			globalBal -= amt;

			printf("\nDebted from %d cutomer Acc | Balance = %d | Amt = %d | Global Bal = %d \n", *u , balance[*u] , amt , globalBal);
			
		}
		sem_post(&mutex);


		// debit

	}



	sem_post(&counter);

	sleep(1);
}


int main()
{
	
	sem_init(&mutex , 0, 1);

	sem_init(&counter , 0, 3);

	globalMinBal = 100*C_COUNT;

	pthread_t c[C_COUNT];

	int i;

	for ( i = 0; i < C_COUNT; ++i)
	{	
		balance[i] = 100 + rand()%1000;
		globalBal += balance[i];
		val[i] = i;
		pthread_create(&c[i], NULL , transact , &val[i]);
	}

	for ( i = 0; i < C_COUNT; ++i)
	{
		pthread_join(c[i], NULL);
	}


	return 0;
}