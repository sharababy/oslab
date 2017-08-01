#include <stdio.h>
#include "scheduler.h"

int main()
{
	int k=1, btime=0, min, temp;
	for (int i = 0; i < 5; ++i)
	{
		pid[i]=i+1;
		printf("\nProcess ID: %d", pid[i]);
		printf("\nEnter the arrival time: ");
		scanf("%d", &at[i]);
		printf("Enter the burst time: ");
		scanf("%d", &bt[i]);
	}
	ct[0]=at[0]+bt[0];
	tat[0]=ct[0]-at[0];
	wt[0]=tat[0]-bt[0];
	for (int i = 0; i < 5; ++i)
	{
		btime+=bt[i];
		min=bt[k];
		for (int j = k; j < 5; ++j)
		{
			if (btime>=at[j] && min>bt[j])
			{
				temp=pid[k];
				pid[k]=pid[j];
				pid[j]=temp;
				
				temp=at[k];
				at[k]=at[j];
				at[j]=temp;
				
				temp=bt[k];
				bt[k]=bt[j];
				bt[j]=temp;
			}
		}
		k++;
	}
	for (int i = 1; i < 5; ++i)
	{
		ct[i]=ct[i-1]+bt[i];
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	printf("\nK= %d", k);
	printf("\nShortest Job First Processing Schedule: ");
	printf("\n--------------------------------------");
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
	return 0;
}