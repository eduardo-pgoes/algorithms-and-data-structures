/*
    Queue linked list implementation
    Motivation: it's way easier to store other data structures (for example, binary tree nodes instead of ints) this way
*/
#include <stdio.h>
#include <stdlib.h>

#pragma region Queue

/**
 * \struct Represents a linked list with queue data
*/
struct QueueNode {
    int data;
    struct QueueNode *next;
};

/**
 * \struct Represents a queue
*/
struct Queue {
    struct QueueNode *front, *rear;
};

/**
 * \brief Creates a new queue node.
 * \param data Data to be added into the node.
 * \return Pointer to the queue node.
*/
struct QueueNode* newQueueNode(int data) {
    struct QueueNode* q = malloc(sizeof *q);
    q->data = data;
    q->next = NULL;
    return q;
}

/**
 * \brief Creates a new queue.
 * \return Pointer to the new queue.
*/
struct Queue* createQueue() {
    struct Queue *q = malloc(sizeof *q);
    q->front = NULL;
    q->rear = NULL;
    return q;
}

/**
 * \brief Enqueue some data.
 * \param q Pointer to the queue.
 * \param data Data to enqueue.
*/
void enqueue(struct Queue *q, int data) {
    struct QueueNode *temp = newQueueNode(data);

    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

/**
 * \brief Dequeue an element.
 * \param q Pointer to the queue.
*/
void dequeue(struct Queue *q) {
    if (q->front == NULL) return;

    struct QueueNode *temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

#pragma endregion Queue

void printQueue(struct Queue *q) {
    struct QueueNode *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printQueue(q);
}