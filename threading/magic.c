#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


#define SIZE 7


int square[SIZE][SIZE];
int sum;

void *generateSquare(void * p)
{
    int n = *(int*)p;
    int magicSquare[n][n]; 
    
    memset(magicSquare, 0, sizeof(magicSquare));
    
    int i = n/2;
    int j = n-1;
 
    int num;
    for (num=1; num <= n*n; )
    {
        if (i==-1 && j==n)
        {
            j = n-2;
            i = 0;
        }
        else
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i=n-1;
        }
        if (magicSquare[i][j])         {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;
 
        j++; i--;
    }
 
    
    printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n",
            n, n*(n*n+1)/2);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++){
            printf("%3d ", magicSquare[i][j]);
            square[i][j] = magicSquare[i][j];
        }
        printf("\n");
    }

    pthread_exit(0);
    // 08791b398cef629a02d7c94168fee7dbf22ca69d
}

void* verticalCheck(void* p){

    int index = *(int*)p;

    int i,check = 0;

    for (i = 0; i < SIZE; ++i)
    {
        check += square[i][index];
    }

    if (check == sum)
    {
        printf("Verifed Row %d \n", index);
    }

    pthread_exit(0);
}

void* horizontalCheck(void* p){

    int index = *(int*)p;

    int i,check = 0;

    for (i = 0; i < SIZE; ++i)
    {
        check += square[index][i];
    }

    if (check == sum)
    {
        printf("Verifed Col %d \n", index);
    }

    pthread_exit(0);
}


 
int main()
{
    int n = SIZE; 
    

    sum = n*(n*n+1)/2;

    pthread_attr_t tattr;
    pthread_attr_init(&tattr);
    pthread_attr_setschedpolicy(&tattr, SCHED_OTHER);
    pthread_t make_square;

    pthread_create(&make_square , NULL , generateSquare , &n);

    pthread_join(make_square,NULL);

    int thread_count = n + n + 2;

    pthread_t vertical_checker_threads[n];
    pthread_t horizontal_checker_threads[n];

    int i,v[n],h[n];

    for (i = 0; i < n ; ++i)
    {
        v[i] = i;
        pthread_create(&vertical_checker_threads[i] , &tattr , verticalCheck , &v[i]);
    }
    for (i = 0; i < n; ++i)
    {
        pthread_join(vertical_checker_threads[i] , NULL);
    }

    for (i = 0; i < n; ++i)
    {
        h[i] = i;
        pthread_create(&horizontal_checker_threads[i] , &tattr , horizontalCheck , &h[i]);
    }
    for ( i = 0; i < n; ++i)
    {
        pthread_join(horizontal_checker_threads[i] , NULL);
    }
    

    return 0;
}
