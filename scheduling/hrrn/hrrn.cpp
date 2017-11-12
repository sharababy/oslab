#include <stdio.h>
#include "scheduler.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>


using namespace std; 



int main()
{
	srand(time(NULL));
	int pid[5]={3,1,4,5,2} ,at[5] = {1,2,3,5,6}, bt[5] = {4,3,5,2,6},pri[5]={0,0,0,0,0};
	
	

/*	for(int i=0;i<5;i++){
		
		at[i] = rand()%10 + 1;
		bt[i] = rand()%10 + 1;
		pri[i] = rand()%10 + 1;
	}
*/
	hrrn_gen(pid,at,bt,pri);
	
	return 0;
}
