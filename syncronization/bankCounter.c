#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define C_COUNT 11

#define RED     "\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[36m"
#define RESET   "\033[0m"


int balance[C_COUNT], val[C_COUNT], globalBal, globalMinBal,counterNo,trans,token;

sem_t counter,mutex,cmut;


void* transact(void * arg){

	int *u = arg;

	printf("\n%d customer Entered Bank \n", *u);

	sleep(1);
	sem_wait(&counter);

	sem_wait(&cmut);
	counterNo++;
	token++;
	sem_post(&cmut);

	printf(BLUE"\n%d customer got Counter %d and Token ID %d", *u,counterNo,token );
	printf(RESET"\n");
	sleep(1);

	int transactionType = rand()%2;

	if (transactionType == 0)
	{
		// credit

		sem_wait(&mutex);

		trans++;
		int amt = rand()%1000;

		balance[*u] += amt;

		globalBal += amt;

		printf(GREEN"\nCredited from %d cutomer \n\t Acc Balance = %d \n\t Amt = %d \n\t Global Bal = %d \n\t Transaction ID = %d\n\n", *u , balance[*u] , amt , globalBal,trans);
		printf(RESET"\n");
		sem_post(&mutex);

		// credit
	}

	else if(transactionType == 1){

		// debit

		sem_wait(&mutex);

		trans++;
		int amt = rand()%1000;

		if ((balance[*u]-amt) <= 100 || (globalBal-amt) <= globalMinBal)
		{
			printf(RED"\nCannot debit from %d cutomer \n\t Acc Balance = %d \n\t Amt = %d \n\t Global Bal = %d \n\t Transaction ID = %d\n\n", *u , balance[*u] , amt , globalBal,trans);
			printf(RESET"\n");
		}
		else{



			balance[*u] -= amt;

			globalBal -= amt;

			printf(GREEN"\nDebted from %d cutomer\n\t Acc Balance = %d \n\t Amt = %d \n\t Global Bal = %d \n\t Transaction ID = %d\n\n", *u , balance[*u] , amt , globalBal,trans);
			printf(RESET"\n");
		}
		sem_post(&mutex);


		// debit

	}

	sem_wait(&cmut);
	counterNo--;
	sem_post(&cmut);

	sem_post(&counter);
	
	sleep(1);
}


int main()
{	
	counterNo = 0;
	trans = 0;
	token =0;

	sem_init(&mutex , 0, 1);

	sem_init(&cmut , 0, 1);

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