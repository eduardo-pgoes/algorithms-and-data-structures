/*
    Bubble sort algorithm implementation that swaps values with pointers (passing values through references)
*/
#include <stdio.h>

#define SIZE 10
/* Function prototypes */
void bubbleSort(int *array, const int size);
void printArray(int *array, const int size);
void swap(int *e1Ptr, int *e2Ptr);

/* Function implementations */

/* Sorts array's value into ascending order */
void bubbleSort(int *array, const int size) {
    int pass; /* Counts how many times the array has been passed */
    int i; /* Comparsions counter */
    int hold; /* Holds elements for swapping */
    for (pass = 1; pass < size; pass++) {
        for (i = 0; i < size-1; i++) {
            if (array[i] > array[i+1]) {
                swap(&array[i], &array[i+1]);
            }
        }
    }
}

/* Loops through array elements and prints them */
void printArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, array[i]);
    }
}

/* Swaps values in an array */
void swap(int *e1Ptr, int *e2Ptr) {
    int hold = *e1Ptr;
    *e1Ptr = *e2Ptr;
    *e2Ptr = hold;
}

int main() {
    int array[SIZE] = {9, 7, 5, 4, 3, 2, 1, 6, 8, 0};
    /* Unsorted array visualization */
    printf("Unsorted array:\n");
    printArray(array, SIZE); 
    printf("Sorted array:\n");
    bubbleSort(array, SIZE);
    printArray(array, SIZE);
    return 0;
}