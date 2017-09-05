
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

	pid_t pid = fork();
	
	if(pid==0){


		printf("\n-- We are in the child\n");

		
		
	}
	else{
		
		
		printf("\n-- We are in the parent\n");

		sleep(2);
		
		printf("\nZombie Parent coming through...\n");
		
		sleep(2);	
		printf("\n-- We are still in the parent\n");
		printf("\nParent EXIT");
	}


	return 0;

}
