
#include <stdio.h>
#include <stdlib.h>


int ct[5], tat[5], wt[5];


int compare(const void * a , const void * b){

	return (*(int*)a - *(int*)b );

}

void pp_gen(int pid[] , int at[] , int bt[],int pri[]){
	
	int temp;
	
	qsort(at,5,sizeof(int),compare);
	qsort(pri,5,sizeof(int),compare);

	printf("Arrival: \n");
	for (int d = 0; d < 5; ++d)
		{
			printf("%d ", at[d]);
		}
		printf("\nBurst:\n");
	for (int d = 0; d < 5; ++d)
		{
			printf("%d ", bt[d]);
		}
		printf("\n");
		printf("Priority:\n");
	for (int d = 0; d < 5; ++d)
		{
			printf("%d ", pri[d]);
		}
		printf("\n");

	ct[0]=at[0]+bt[0];
	tat[0]=ct[0]-at[0];
	wt[0]=tat[0]-bt[0];

	int last = 0,index=0;

	int pre[5]={100,100,100,100,100},u=0;
		
	
	for (int i = 1; i < 5; ++i)
	{   
		int min = 100;
		for(int k=1 ; k<5 ; k++){
			
			if(ct[last] >= at[k] && pre[k] != 101 ){
				pre[k] = bt[k];
				u++; 				
			}
		}
		

 		if(u==0){
			printf("\n\nNo more processes!\n\n");
			break;
		}
		else{
			/*for(int k=0 ; k<5 ; k++){
				printf(" %d ",pre[k]);
			}*/			
			

				
					min = pri[i];
					index=i;
					
				//printf("min: %d , index: %d \n",min,index);

				if(min!=100){
					pre[index] = 101;
					
				//	printf("\n\nct[last]: %d , min: %d ,index: %d , last: %d \n\n",ct[last],min,index,last);
					ct[index]=ct[last]+ min;
					tat[index]=ct[index]-at[index];
					wt[index]=tat[index]-bt[index];
					last = index;


				}
				
		}
	}
	printf("\nPriority Scheduling: ");
	printf("\n---------------------------------------------------");
	
	
		for (int i = 0; i < 5; ++i)
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
