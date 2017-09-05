
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
	int reach;
	printf("\nEnter : ");
	scanf("%d",&reach);


	pid_t pid = fork();
	


	if(pid==0){

		printf("\n-- We are in the child\n");
		int i =0;
		for(i = 0 ; i < reach; i++){

			if(i%2 == 0)  printf(" %d ",i);
		}

		printf("\n");
	}
	else{

		printf("\n-- We are in the parent\n");
		
		int i =0;
		for(i = 0 ; i < reach ; i++){

			if(i%2!=0 ) printf(" %d ",i);
		}
		printf("\n");
	}


	return 0;

}

