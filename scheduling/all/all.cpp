#include <stdio.h>
#include "scheduler.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>


using namespace std; 



int main()
{
	srand(time(NULL));
	int pid[6]={1,2,3,4,5,6} ,at[6] = {1,2,2,3,3,4}, bt[6] = {4,2,3,5,1,2},pri[6]={4,5,7,8,5,6};
	
	/*for(int i=0;i<6;i++){
		
		at[i] = rand()%10 + 1;
		bt[i] = rand()%10 + 1;
		pri[i] = rand()%10 + 1;
	}*/

	pp_gen(pid,at,bt,pri);
	srt_gen(pid,at,bt);
	hrrn_gen(pid,at,bt,pri);
	pnp_gen(pid,at,bt,pri);
	rr_gen(pid,at,bt);
	sjf_gen(pid,at,bt);




	return 0;
}


// ct: 25 , 22 , 21 , 12 , 19 , 9 , 18
