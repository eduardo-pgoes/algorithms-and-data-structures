/*
    Consider the searching problem:

    Input: A sequence of n numbers 〈a1, a2, … , an〉 stored in array A[1 : n] and a value x.

    Output: An index i such that x equals A[i] or the special value NIL if x does not appear in A.
*/
#include <stdio.h>
#define SIZE 5

/* Function prototypes */
int linearSearch(int* array, int x, const int size);
void printArray(int *array, const int size);

/* Linear search implementation */
int linearSearch(int* array, int x, const int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}

void printArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, array[i]);
    }
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int x;
    printf("Insert an element to search for: ");
    scanf("%d", &x);
    printf("Index where %d resides: ", x);
    printf("%d", linearSearch(arr, x, SIZE));
    return 0;
}