#include<stdio.h>

// Quick Sort uses a pivot element and partitions the array into smaller and larger values.
// This file demonstrates the algorithm by sorting a fixed global array.
int Arr[] = {43,45,98,23,21,5,1,8,2,6,77,18,4};

// Return the final index of the pivot after arranging elements around it.
int pivot(int *Arr,int low,int high) {
    // Select the last element as the pivot value.
    int v = Arr[high];
    int i, s, j = low;
    for(i = low;i < high;i++) {
        if(Arr[i] <= v) {
            s = Arr[j];
            Arr[j] = Arr[i];
            Arr[i] = s;
            j = j+1;
        }
    }
    // Place the pivot in its final sorted position.
    s = Arr[j];
    Arr[j] = Arr[high];
    Arr[high] = s;
    return j;
}

// Recursively sort the left and right partitions around the pivot.
void quicksort(int *Arr,int low,int high) {
    if(low < high) {
        int p = pivot(Arr,low,high);
        quicksort(Arr,low,p - 1);
        quicksort(Arr,p + 1, high);
    }
}

int main() {
    // Determine the number of elements in the global array.
    int i, n = sizeof(Arr)/sizeof(Arr[0]);
    printf("Before Sort:\n");
    for(i = 0;i < n;i++) {
        printf("%d ",Arr[i]);
    }
    printf("\n");
    
    // Sort the array using the recursive quicksort method.
    quicksort(Arr,0,n-1);

    // Print the array after sorting is complete.
    printf("After Sort:\n");
    for(i = 0;i < n;i++) {
        printf("%d ",Arr[i]);
    }
    printf("\n");
    return 0;
}