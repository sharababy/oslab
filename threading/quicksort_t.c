#include <stdio.h>
#include <pthread.h>

#define SIZE 10
  

typedef struct Set{

    int *arr;
    int low;
    int high;
    
} set;



void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int j,i = (low - 1);  // Index of smaller element
 
    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
  
 
  
  
void *quickSort(void * s)
{
	set *d = (set *)s;
	
    if (d->low < d->high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(d->arr, d->low, d->high);
 
 	set f,g;
 	f.arr = d->arr;
 	f.low = d->low;
 	f.high = (pi)-1;
 	
 	g.arr = d->arr;
 	g.low = (pi)+1;
 	g.high = d->high;
 	
 	pthread_t t1,t2;
    pthread_attr_t tattr;
    pthread_attr_init(&tattr);
    pthread_attr_setschedpolicy(&tattr, SCHED_OTHER);
    
    // Separately sort elements before
    // partition and after partition
    pthread_create(&t1 , &tattr , quickSort , &f );
    pthread_create(&t2 , &tattr , quickSort , &g );
        
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    }


    pthread_exit(0);
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[SIZE] = {10, 7, 8, 2, 1, 5,19,3,22,11};
    int n = SIZE;

    pthread_t t2;
    set g;

    g.arr = arr;
    g.low = 0;
    g.high = n-1;
    

    pthread_create(&t2 , NULL , quickSort , &g );

    pthread_join(t2,NULL);

    printf("Sorted array:\n");

    printArray(arr, n);
    return 0;
}
