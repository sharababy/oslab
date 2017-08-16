
#include <stdio.h>
#include <stdlib.h>

#define size 6
int ct[size], tat[size], wt[size];


int compare(const void * a , const void * b){

	return (*(int*)a - *(int*)b );

}

void rr_gen(int pid[] , int at[] , int bt[]){
	
	int temp;
	
	qsort(at,size,sizeof(int),compare);

	printf("Arrival: \n");
	for (int d = 0; d < size; ++d)
		{
			printf("%d ", at[d]);
		}
		printf("\nBurst:\n");
	for (int d = 0; d < size; ++d)
		{
			printf("%d ", bt[d]);
		}
		printf("\n");

	int tq = 3;
	int pq[size]={100,100,100,100,100,100};
	int qq[200] = {100} ,v=0,begining=0;
	
	qq[0] = 0;
	v++;
	pq[0] = bt[0];
	int last = 0,index=0;
	
	int pending	= 1;
	int current = 1;
	

	for (int i = at[0]; pending != 0; i = i+tq)
	{   

		tq=3;
		
		for (int d = 0; d < size; ++d) // to check for arriving processes 
		{
			if (at[d] <= i && pq[d] == 100 )
				{
					pq[d] = bt[d];
					qq[v] = d;
					v++;	
				}	
		}

		for (int d = 0; d < size; ++d) // to check for completed processes
		{
			if (pq[d] == 0)
				{
					pq[d] = 101;
					ct[d] = i;
					tat[d] = ct[d] - at[d];
					wt[d]=tat[d]-bt[d];
				}	
		}

		int u = 0;
		for (int d = 0; d < size; ++d) // to check for current processes 
		{
			if (pq[d] != 100 && pq[d] != 101)
				{
					u++;
				}	
		}

		pending = u;

		for(int k=0 ; k<size; k++){
			printf(" %d ",pq[k]);
		}
		printf("-- Q: ");
		for(int k=begining ; k<v; k++){
			printf(" %d ",qq[k]);
		}

		printf(" -- Time: %d \n",i);
		

 		if(u==0){
			//printf("\n\nNo more processes!\n\n");
			break;
		}
		else{
			/*for(int k=0 ; k<size; k++){
				printf(" %d ",pre[k]);
			}*/			
			
			//decide which process will be executed next based on queue

			index = qq[begining];

			//printf("min: %d , index: %d \n",min,index);

			temp = pq[index] - tq;

			if(temp <= 0){
				temp = 0;
				tq = pq[index];
				
			}
			else{
				qq[v] = index;
				v++;
			}
			begining++;
			pq[index]=temp;
			
				
		}
		
		/*for (int d = 0; d < size; ++d)
		{
			printf("%d ", pq[d]);
		}*/
		//printf("Current time: %d , pending: %d ,min: %d , index: %d , temp: %d\n",i,u,min,index,temp);


	}
	printf("\nRound Robbin Schedule: ");
	printf("\n----------------------");
	
	
		for (int i = 0; i < size; ++i)
		{
			printf("\nProcess ID: %d", pid[i]);
			printf("\tArrival Time: %d", at[i]);
			printf("\tBurst Time: %d", bt[i]);
			printf("\tCompletion Time: %d", ct[i]);
			printf("\tTurn-around Time: %d", tat[i]);
			printf("\tWaiting Time: %d", wt[i]);
		}
	
	printf("\n");



}
