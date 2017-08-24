#include <stdio.h>
#include "scheduler.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>


using namespace std; 



int main()
{
	srand(time(NULL));
	int pid[3]={1,2,3} ,at[3] = {1,2,3}, bt[3] = {4,2,3},pri[3]={4,5,7};
	
	/*for(int i=0;i<6;i++){
		
		at[i] = rand()%10 + 1;
		bt[i] = rand()%10 + 1;
		pri[i] = rand()%10 + 1;
	}*/

	pp_gen(pid,at,bt,pri);
	
	return 0;
}


// ct: 25 , 22 , 21 , 12 , 19 , 9 , 18
