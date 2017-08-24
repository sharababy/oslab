#include <stdio.h>
#include <stdlib.h>

#define size 3

int ct[size], tat[size], wt[size];


int compare(const void * a , const void * b){

	return (*(int*)a - *(int*)b );

}

void pp_gen(int pid[] , int at[] , int bt[],int pri[]){
	

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
		printf("Priority:\n");
	for (int d = 0; d < size; ++d)
		{
			printf("%d ", pri[d]);
		}
		printf("\n");

	int tq = 1;
	int pq[size]={-1,-1,-1};
	int qq[200] = {-1} ,v=0,begining=0;
	int priq[size]={-1,-1,-1};
	
	

	int last = 0,index=0;
	
	int pending= 1;
	int current = 1;

	pq[0] = bt[0];
	priq[0]=pri[0];
	
	for (int i = ct[0]; pending != 0; i++)
	{   

		
		for (int d = 0; d < size; ++d) // to check for arriving processes 
		{
			if (at[d] <= i && pq[d] == -1 )
				{
					pq[d] = bt[d];
					priq[d] = pri[d];  
						
				}	
		}

		
		for (int d = 0; d < size; ++d) // to check for completed processes
		{
			if (pq[d] == 0)
				{
					pq[d] = -2;
					priq[d] = -2;
					ct[d] = i;
					tat[d] = ct[d] - at[d];
					wt[d]=tat[d]-bt[d];
				}	
		}

		int u = 0;
		for (int d = 0; d < size; ++d) // to check for current processes 
		{
			if (pq[d] != -1 && pq[d] != -2)
				{
					u++;
				}	
		}

		pending = u;

		/*for(int k=0 ; k<size; k++){
			printf(" %d ",pq[k]);
		}
		printf("-- Q: ");
		for(int k=begining ; k<v; k++){
			printf(" %d ",qq[k]);
		}

		printf(" -- Time: %d \n",i);
		*/

 		if(u==0){
			//printf("\n\nNo more processes!\n\n");
			break;
		}
		else{
			int max = -1;
			/*for(int k=0 ; k<size; k++){
				printf(" %d ",pre[k]);
			}*/			
			
                        
			for(int hh = 0; hh<size ; hh++){
				if(priq[hh] > max){
				max = priq[hh];
				index = hh;
				}
			}

			//printf("min: %d , index: %d \n",min,index);

			temp = pq[index] - 1;

			pq[index]=temp;
			
				
		}
		
		/*for (int d = 0; d < size; ++d)
		{
			printf("%d ", pq[d]);
		}*/
		//printf("Current time: %d , pending: %d ,min: %d , index: %d , temp: %d\n",i,u,min,index,temp);


	}

	printf("\nPriority Scheduling Preemptive: ");
	printf("\n---------------------------------------------------");
	
	
		for (int i = 0; i < size; ++i)
		{
			printf("\nProcess ID: %d", pid[i]);
			printf("\tArrival Time: %d", at[i]);
			printf("\tBurst Time: %d", bt[i]);
			printf("\tPriority : %d", pri[i]);
			printf("\tCompletion Time: %d", ct[i]);
			printf("\tTurn-around Time: %d", tat[i]);
			printf("\tWaiting Time: %d", wt[i]);
		}
	
	printf("\n");



}
