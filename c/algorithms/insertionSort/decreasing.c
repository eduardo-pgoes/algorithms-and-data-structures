/*
    Cormen exercise where you're supposed to change the Insertion Sort algorithm so it sorts elements in decreasing order
*/

#include <stdio.h>
#define SIZE 5

/* Function prototypes */
void insertionSort(int *array, const int size);
void printArray(int *array, const int size);

/* Function implementations */
void insertionSort(int *array, const int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i-1;
        while (j >= 0 && array[j] < key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

// Prints array into std:out
void printArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, array[i]);
    }
}

int main() {
    int arr[] = {2, 5, 1, 4, 3};
    printf("Before sorting:\n");
    printArray(arr, SIZE);
    printf("After sorting:\n");
    insertionSort(arr, SIZE);
    printArray(arr, SIZE);
    return 0;
}