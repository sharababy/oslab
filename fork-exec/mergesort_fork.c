#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int start , int size)
{
    int i;
    for (i=start; i < size; i++)
        printf("%d ", A[i]);
    
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {9, 1, 3, 5, 6, 17, 10, 44, 13, 19};
    int arr_size = sizeof(arr)/sizeof(arr[0]);


    // need to ensure that all elements in left half are 
    //smaller than all elements in right half

    int pivot = 4;

    printf("Given array is \n");
    printf("\n");
    printArray(arr,0, arr_size);



    printf("\nSorted array is \n");
    
    
    pid_t pid = fork();


    if(pid==0){

        mergeSort(arr, 0, pivot);
        printArray(arr, 0, pivot+1);
    }
    else{

        wait(NULL);
        mergeSort(arr, pivot+1 , arr_size-1);
        printArray(arr, pivot+1 , arr_size);
        
        //merge(arr, 0 , pivot , arr_size-1);    
    }

    //printArray(arr, arr_size);
    return 0;
}