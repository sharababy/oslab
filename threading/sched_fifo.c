#include <stdio.h>
#include <pthread.h>

void* det(){

	system("./determinant_t");

	pthread_exit(0);
}
void* m(){

	system("./matmul_threading");

	pthread_exit(0);
}
void* ma(){

	system("./magic");


	pthread_exit(0);
}
void* q(){

	system("./quicksort_t");

	pthread_exit(0);
}

int main(){
	
	pthread_attr_t tattr;
    pthread_attr_init(&tattr);
    pthread_attr_setschedpolicy(&tattr, SCHED_FIFO);
    pthread_t t[4];

    int  i;
    
    pthread_create(&t[0] , &tattr , det , NULL);
    pthread_create(&t[1] , &tattr , m , NULL);
    pthread_create(&t[2] , &tattr , ma , NULL);
    pthread_create(&t[3] , &tattr , q , NULL);
    for ( i = 0; i < 4; ++i)
    {
    	pthread_join(t[i] , NULL);
    }
    	
    return 0;
}