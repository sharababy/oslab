
#include <stdio.h>
#include <stdlib.h>


int ct[5], tat[5], wt[5];


int compare(const void * a , const void * b){

	return (*(int*)a - *(int*)b );

}

void srt_gen(int pid[] , int at[] , int bt[]){
	
	int temp;
	
	qsort(at,5,sizeof(int),compare);

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


	int rt[5]={100,100,100,100,100};
	
	rt[0] = bt[0]-1;
	
	int last = 0,index=0;
	
	int pending	= 1;
	int current = 1;
	

	for (int i = at[0]; pending != 0; ++i)
	{   

		

		for (int d = 0; d < 5; ++d) // to check for arriving processes 
		{
			if (at[d] == i)
				{
					rt[d] = bt[d];

				}	
		}

		for (int d = 0; d < 5; ++d) // to check for completed processes
		{
			if (rt[d] == 0)
				{
					rt[d] = 101;
					ct[d] = i;
					tat[d] = ct[d] - at[d];
					wt[d]=tat[d]-bt[d];
				}	
		}

		int u = 0;
		for (int d = 0; d < 5; ++d) // to check for current processes [correct]
		{
			if (rt[d] != 100 && rt[d] != 101)
				{
					u++;
				}	
		}

		pending = u;

		int min = 101;
		

 		if(u==0){
			//printf("\n\nNo more processes!\n\n");
			break;
		}
		else{
			/*for(int k=0 ; k<5 ; k++){
				printf(" %d ",pre[k]);
			}*/			
			

			for(int k =0; k<5 ; k++){
				if(min > rt[k]){	
					min = rt[k];
					index=k;
				}
			}			
				//printf("min: %d , index: %d \n",min,index);

			temp = rt[index];
			
			rt[index]=temp-1;
			
				
		}
		/*for (int d = 0; d < 5; ++d)
		{
			printf("%d ", rt[d]);
		}*/
		//printf("Current time: %d , pending: %d ,min: %d , index: %d , temp: %d\n",i,u,min,index,temp);


	}
	printf("\nShortest Remaining Time First Processing Schedule: ");
	printf("\n---------------------------------------------------");
	
	
		for (int i = 0; i < 5; ++i)
		{
			printf("\nProcess ID: %d", pid[i]);
			printf("\tArrival Time: %d", at[i]);
			printf("\tBurst Time: %d", bt[i]);
			printf("\tCompletion Time: %d", ct[i]);
			printf("\tTurn-around Time: %d", tat[i]);
			printf("\tWaiting Time: %d", wt[i]);
		}
	
	printf("\n");

	int avgwt = 0;
	for (int i = 0; i < 5; ++i)
	{
		avgwt+=wt[i];
	}

	printf("Average waittime: %d\n", avgwt/5);


}
