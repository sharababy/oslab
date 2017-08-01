#include <stdio.h>
#include "scheduler.h"
int main()
{
	for (int i = 0; i < 5; ++i)
	{
		pid[i]=i+1;
		printf("\nProcess ID: %d", pid[i]);
		printf("\nEnter the arrival time: ");
		scanf("%d", &at[i]);
		printf("Enter the burst time: ");
		scanf("%d", &bt[i]);

		if (pid[i]==0)
			ct[i]=at[i]+bt[i];
		else
			ct[i]=ct[i-1]+bt[i];
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	printf("\nFirst Come First Serve Processing Schedule: ");
	printf("\n------------------------------------------");

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