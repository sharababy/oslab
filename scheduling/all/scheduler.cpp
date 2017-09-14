
#include <stdio.h>
#include <stdlib.h>


#define size 6

int ct[size], tat[size], wt[size];


int compare(const void * a , const void * b){

	return (*(int*)a - *(int*)b );

}

void hrrn_gen(int pid[] , int at[] , int bt[],int pri[]){
	
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

	ct[0]=at[0]+bt[0];
	tat[0]=ct[0]-at[0];
	wt[0]=tat[0]-bt[0];

	int last = 0,index=0;

	int pre[size]={100,100,100,100,100,100},u=0;
	float rr[size] = {-2,-1,-1,-1,-1};		
		

	for (int i = 1; i < size; ++i)
	{   
		float max = -1;
		for(int k=1 ; k<size ; k++){
			
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
			/*for(int k=0 ; k<size ; k++){
				printf(" %d ",pre[k]);
			}*/			
			
			for(int ff =1 ; ff < size ; ff++){
				if(rr[ff]!=-2){
					rr[ff] = (ct[last] - at[ff] + bt[ff])/bt[ff];
					//printf(" %f ",rr[ff]);
				}
			}
		

			for(int k =1; k<size ; k++){
				if(max < rr[k]){	
					max = pre[k];
					index=k;
				}
			}			
					
			//printf("min: %d , index: %d \n",min,index);

			if(max!=101){
			pre[index] = 101;
			rr[index] = -2;				
			//printf("\n\nct[last]: %d , max: %f ,index: %d , last: %d  \n\n",ct[last],max,index,last);
			ct[index]=ct[last]+ max;
			tat[index]=ct[index]-at[index];
			wt[index]=tat[index]-bt[index];
			last = index;


			}
				
		}
	}
	printf("\nHRRN Scheduling: ");
	printf("\n-------------------------------------------------------------------------------------------");
	
	
		for (int i = 0; i < size; ++i)
		{
			printf("\nProcess ID: %d", pid[i]);
			printf("\tArrival Time: %d", at[i]);
			printf("\tBurst Time: %d", bt[i]);
			printf("\tCompletion Time: %d", ct[i]);
			printf("\tTurn-around Time: %d", tat[i]);
			printf("\tWaiting Time: %d   ", wt[i]);
		}
	
	printf("\n");

	float avgwt = 0;
	for (int i = 0; i < size; ++i)
	{
		avgwt+=wt[i];
	}

	printf("Average waittime: %f\n", avgwt/size);

}


void pnp_gen(int pid[] , int at[] , int bt[],int pri[]){
	
	int temp;
	
	qsort(at,size,sizeof(int),compare);
	qsort(pri,size,sizeof(int),compare);

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

	ct[0]=at[0]+bt[0];
	tat[0]=ct[0]-at[0];
	wt[0]=tat[0]-bt[0];

	int last = 0,index=0;

	int pre[size]={100,100,100,100,100,100},u=0;
		
	
	for (int i = 1; i < size; ++i)
	{   
		int min = 100;
		for(int k=1 ; k<size ; k++){
			
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
			/*for(int k=0 ; k<size ; k++){
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

	float avgwt = 0;
	for (int i = 0; i < size; ++i)
	{
		avgwt+=wt[i];
	}

	printf("Average waittime: %f\n", avgwt/size);


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
	int pq[size]={-1,-1,-1,-1,-1,-1};
	int qq[200] = {-1} ,v=0,begining=0;
	int priq[size]={-1,-1,-1,-1,-1,-1};
	
	

	int last = 0,index=0;
	
	int pending= 1;
	int current = 1;
	
	for (int i = at[0]; pending != 0; i++)
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

	float avgwt = 0;
	for (int i = 0; i < size; ++i)
	{
		avgwt+=wt[i];
	}

	printf("Average waittime: %f\n", avgwt/size);

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
	int remaining = 200;	

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

		if (remaining != 200)
		{
			qq[v] = remaining;
			v++;
			remaining=200;
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
				remaining = index;
				
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

	printf("Gantt Chart: ");
	for (int d = 0; d < v; ++d)
		{
			printf("%d  ", qq[d]);
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

	float avgwt = 0;
	for (int i = 0; i < size; ++i)
	{
		avgwt+=wt[i];
	}

	printf("Average waittime: %f\n", avgwt/size);


}



void sjf_gen(int pid[] , int at[] , int bt[]){
	

	qsort(at,size,sizeof(int),compare);

	ct[0]=at[0]+bt[0];
	tat[0]=ct[0]-at[0];
	wt[0]=tat[0]-bt[0];

	int last = 0,index=0;

		int pre[size]={100,100,100,100,100,100},u=0;
		
	
	for (int i = 1; i < size; ++i)
	{   
		int min = 100;
		for(int k=1 ; k<size ; k++){
			
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
			/*for(int k=0 ; k<size ; k++){
				printf(" %d ",pre[k]);
			}*/			
			

			for(int k =0; k<size ; k++){
				if(min > pre[k]){	
					min = pre[k];
					index=k;
				}
			}			
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
	printf("\nShortest Job First Processing Schedule: ");
	printf("\n--------------------------------------");
	
	
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
	float avgwt = 0;
	for (int i = 0; i < size; ++i)
	{
		avgwt+=wt[i];
	}

	printf("Average waittime: %f\n", avgwt/size);

}



void srt_gen(int pid[] , int at[] , int bt[]){
	
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


	int rt[size]={100,100,100,100,100,100};
	
	rt[0] = bt[0]-1;
	
	int last = 0,index=0;
	
	int pending	= 1;
	int current = 1;
	

	for (int i = at[0]; pending != 0; ++i)
	{   

		

		for (int d = 0; d < size; ++d) // to check for arriving processes 
		{
			if (at[d] == i)
				{
					rt[d] = bt[d];

				}	
		}

		for (int d = 0; d < size; ++d) // to check for completed processes
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
		for (int d = 0; d < size; ++d) // to check for current processes [correct]
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
			/*for(int k=0 ; k<size ; k++){
				printf(" %d ",pre[k]);
			}*/			
			

			for(int k =0; k<size ; k++){
				if(min > rt[k]){	
					min = rt[k];
					index=k;
				}
			}			
				//printf("min: %d , index: %d \n",min,index);

			temp = rt[index];
			
			rt[index]=temp-1;
			
				
		}
		/*for (int d = 0; d < size; ++d)
		{
			printf("%d ", rt[d]);
		}*/
		//printf("Current time: %d , pending: %d ,min: %d , index: %d , temp: %d\n",i,u,min,index,temp);


	}
	printf("\nShortest Remaining Time First Processing Schedule: ");
	printf("\n---------------------------------------------------");
	
	
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

	int avgwt = 0;
	for (int i = 0; i < size; ++i)
	{
		avgwt+=wt[i];
	}

	printf("Average waittime: %d\n", avgwt/size);


}
