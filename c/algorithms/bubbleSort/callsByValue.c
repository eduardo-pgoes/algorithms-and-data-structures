/*
    Bubble sort algorithm implementation that swaps values without pointers (passes values by themselves)
*/
#include <stdio.h>

#define SIZE 10
/* Function prototypes */
void bubbleSort(int *array, const int size);
void printArray(int *array, const int size);

/* Function implementations */

/* Sorts array's value into ascending order */
void bubbleSort(int *array, const int size) {
    int pass; /* Counts how many times the array has been passed */
    int i; /* Comparsions counter */
    int hold; /* Holds elements for swapping */
    for (pass = 1; pass < size; pass++) {
        for (i = 0; i < size-1; i++) {
            if (array[i] > array[i+1]) {
                hold = array[i];
                array[i] = array[i+1];
                array[i+1] = hold;
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