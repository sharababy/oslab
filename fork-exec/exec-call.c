#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

	pid_t pid = fork();
	
	if(pid==0){

		printf("\n-- We are in the child\n");
		execlp("ls","ls",NULL);

	}
	else{


		printf("\n-- We are in the parent\n");
//		execlp("ls","ls",NULL);
	}


	return 0;

}

