
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define size 10

int main(){
	
	int m[size] = {7,3,9,4,132,67,12,75,44,49};
	int half = size/2;
	int k =0;
	printf("original: ");	
		for(k=0;k<size;k++){

			if(k==half) printf(" ^ ");
			printf(" %d ", m[k]);
		}
		printf("\n\n");
	pid_t pid = fork();
	
	if(pid==0){
		printf("\n-- We are in the child\n");
		int i = 0,j=0;
		int max;
		for(i=0 ; i < half; i++){
			for(j=i ; j < half; j++){
				
				if(m[i] <= m[j]){
					int temp = m[i];
					m[i] = m[j];
					m[j] = temp;
				}
			}



		}
		for(i=0;i<size;i++){

			if(i==half) printf(" ^ ");
			printf(" %d ", m[i]);
		}
		printf("\n\n");
	}
	else{
		printf("\n-- We are in the parent\n");


		int i = 0,j=0;
		int max;
		for(i=half ; i < size; i++){
			for(j=i ; j < size; j++){
				
				if(m[i] >= m[j]){
					int temp = m[i];
					m[i] = m[j];
					m[j] = temp;
				}
			}



		}
		for(i=0;i<size;i++){

			if(i==half) printf(" ^ ");
			printf(" %d ", m[i]);
		}
		printf("\n\n");
	}


	return 0;

}

