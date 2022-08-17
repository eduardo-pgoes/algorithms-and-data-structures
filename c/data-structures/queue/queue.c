/*
    Queue implementation in C
    FIFO policy (First-in, first-out)
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

/* Structure that represents a queue */
struct queue {
    int size;
    int head;
    int tail;
    int *items;
};

/* Function prototypes */
void enqueue(struct queue *q, int x);
int dequeue(struct queue *q);
struct queue* newQueue(int maxSize);

/* Initializes a queue */
struct queue* newQueue(int maxSize) {
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->size = maxSize; 
    q->tail = maxSize - 1;
    q->head = 0;
    q->items = (int*) malloc(sizeof(int) * maxSize);  
}

/* Enqueues an element */
void enqueue(struct queue *q, int x) {
    q->items[q->tail] = x;
    if (q->tail == q->size) {
        q->tail = 1;
    } else {
        q->tail++;
    }
}

/* Returns the first element from the queue */
int dequeue(struct queue *q) {
    int x = q->items[q->head];
    if (q->head == q->size) {
        q->head = 1;
    } else {
        q->head++;
    }
    return x;
}

int main() {
    struct queue *q = newQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("First dequeued item: %d\n", dequeue(q));
    printf("Second dequeued item: %d", dequeue(q));
    return 0;
}