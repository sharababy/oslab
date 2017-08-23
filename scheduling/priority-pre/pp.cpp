#include <stdio.h>
#include "scheduler.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>


using namespace std; 



int main()
{
	srand(time(NULL));
	int pid[6]={1,2,3,4,5,6} ,at[6], bt[6],pri[6];
	
	for(int i=0;i<6;i++){
		
		at[i] = rand()%10 + 1;
		bt[i] = rand()%10 + 1;
		pri[i] = rand()%10 + 1;
	}

	pp_gen(pid,at,bt,pri);
	
	return 0;
}
