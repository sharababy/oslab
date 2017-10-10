#include <stdio.h>
#include <pthread.h>

#define SIZE 5
  
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
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
  
typedef struct Set{

	int arr[SIZE];
	int low;
	int high;
	
} set 
  
  
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
 	f.high = d->pi-1;
 	
 	g.arr = d->arr;
 	g.low = d->pi+1;
 	g.high = d->high;
 	
 	pthread_t t1,t2;
        // Separately sort elements before
        // partition and after partition
        pthread_create(&t1 , NULL , quickSort , &f );
        pthread_create(&t2 , NULL , quickSort , &g );
        
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
 
// Driver program to test above functions
int main()
{
    int arr[SIZE] = {10, 7, 8, 9, 1, 5};
    int n = SIZE;
    quickSort(arr, 0, n-1);
    printf("Sorted array: n");
    printArray(arr, n);
    return 0;
}
