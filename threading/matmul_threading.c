#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define SIZE 3

typedef struct Subcal{

	int row;    
    int row1[SIZE];
    int row2[SIZE];

    int res[SIZE];

} subcal;


void *mul(void* r){
	
	int i,j;
	
	subcal *d = (subcal *)r;
	
/*	for(i=0;i<SIZE;i++){
		d.row1[i] = (subcal *)r->row1[i];
	}
	
	for(i=0;i<SIZE;i++){
		d.row2[i] = (subcal *)r->row2[i];
	}
	
*/	
	for(i=0;i<SIZE;i++){
		d->res[i] = d->row1[i] * d->row2[i];
	}
	
	printf("ROW %d ",d->row);
	for(i=0;i<SIZE;i++){
		printf(" %d ",d->res[i]);
	
	}
	
	printf("\n");
	
	pthread_exit(0);
}


int main(){
    

    pthread_t t[SIZE];
    
    int a[SIZE][SIZE] = { {1,2,3 },{1,2,3},{ 1,2,3} };

    int b[SIZE][SIZE] = { {1,2,3 },{1,2,3},{ 1,2,3} };

    subcal result[SIZE];

    int i,j,k;
    for(i = 0 ; i<SIZE ; i++){
    
	for( j=0 ;j<SIZE; j++)
	{
	  result[i].row = i; 
	  result[i].row1[j] = a[i][j];
	  result[i].row2[j] = b[i][j];
	   
	} 
	pthread_create(&t[i] , NULL , mul ,&result[i]);
    
    }

    for(i = 0 ; i<SIZE ; i++){

	 pthread_join(t[i], NULL );
    
    }

    
	return 0;

}
