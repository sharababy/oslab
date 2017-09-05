
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){

	int m[10] = {7,3,9,4,132,67,12,75,44,49};

	pid_t pid = fork();
	
	if(pid==0){
		printf("\n-- We are in the child\n");
		int i = 0,j=0;
		int max;
		for(i=0 ; i < 10; i++){
			for(j=i ; j < 10; j++){
				
				if(m[i] <= m[j]){
					int temp = m[i];
					m[i] = m[j];
					m[j] = temp;
				}
			}



		}
		for(i=0;i<10;i++){

			printf(" %d ", m[i]);
		}
		printf("\n\n");
	}
	else{
		printf("\n-- We are in the parent\n");


		int i = 0,j=0;
		int max;
		for(i=0 ; i < 10; i++){
			for(j=i ; j < 10; j++){
				
				if(m[i] >= m[j]){
					int temp = m[i];
					m[i] = m[j];
					m[j] = temp;
				}
			}



		}
		for(i=0;i<10;i++){

			printf(" %d ", m[i]);
		}
		printf("\n\n");
	}


	return 0;

}

