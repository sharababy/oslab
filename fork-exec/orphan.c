
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

	pid_t pid = fork();
	
	if(pid==0){
		printf("\nThis child will become an orphan\n");		

		sleep(2);

		printf("\n-- Yay ... we are in the orphan child\n");
	}
	else{


		printf("\n-- We are in the parent\n");
	}


	return 0;

}
