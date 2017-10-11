

#include <stdio.h>
#include <pthread.h>
 

#define N 4
 

typedef struct Set{
    int mat[N][N]; 
    int n;
} set;

void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
 
    int row,col;
    for (row = 0; row < n; row++)
    {
        for ( col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
 
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
void* determinantOfMatrix(void* p)
{
    set *d = (set*)p;

    int D = 0; // Initialize result
 	int i,j;
    
    if (d->n == 1)
        return (void *)&(d->mat[0][0]);
 
    int temp[N][N]; // To store cofactors
 	for ( i = 0; i < N; ++i)
        {
            for ( j = 0; j < N; ++j)
            {
                temp[i][j] = -1;
            }
            
        }
    int sign = 1;  // To store sign multiplier
 
    int f;
    for ( f = 0; f < d->n; f++)
    {
        void *det;
        getCofactor(d->mat, temp, 0, f, d->n);
        
        pthread_t t;
        set s;
        
        for ( i = 0; i < N; ++i)
        {
            for ( j = 0; j < N; ++j)
            {
                s.mat[i][j] = temp[i][j];
            }
            
        }
        s.n = (d->n) - 1;
        pthread_create(&t , NULL , determinantOfMatrix , &s);
        pthread_join(t,&det);
        printf("Return %d\n",*(int*)det );
        D += sign * d->mat[0][f] * (*(int*)det);
    
        sign = -sign;
    }
    
    //printf("Determinant of the matrix is : %d\n",D);
    pthread_exit(&D);
}
 

void display(int mat[N][N], int row, int col)
{
	int i,j;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
            printf("  %d", mat[i][j]);
        printf("n");
    }
}
 

int main()
{
    /* int mat[N][N] = {{6, 1, 1},
                     {4, -2, 5},
                     {2, 8, 7}}; */
 
    int mat[N][N] = {{1, 0, 2, -1},
                     {3, 0, 0, 5},
                     {2, 1, 4, -3},
                     {1, 0, 5, 0}
                    };

    set s;
    int i,j;
    for ( i = 0; i < N; ++i)
    {
        for ( j = 0; j < N; ++j)
        {
            s.mat[i][j] = mat[i][j];
        }
        
    }
        
    s.n = N;
    void *f;
    pthread_t t;
    pthread_attr_t tattr;
    pthread_attr_init(&tattr);
    pthread_attr_setschedpolicy(&tattr, SCHED_FIFO);

    pthread_create(&t , &tattr , determinantOfMatrix , &s);

    pthread_join(t , &f);

    printf("Determinant of the matrix is : %d\n",*(int*)f);
    return 0;
}