/*
    Stack data structure implementation
*/
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
struct stack* newStack(int size);
void push(int x, struct stack *s);
int size(struct stack *s);
int isEmpty(struct stack *s);

/* Structure that represents a stack */
struct stack {
    int size;
    int top;
    int *items;
};

/* Initializes a new fixed size stack. */
struct stack* newStack(int size) {
    struct stack *s = (struct stack*) malloc(sizeof(struct stack));
    s->size = size;
    /*
        Top must be initialized as -1 so the first item to be pushed into the stack
        is passed into items[0].
    */
    s->top = -1;
    s->items = (int*) malloc(sizeof(int) * size); // Initalizing dynamic array
}

/* Pushes an item into the stack. */
void push(int x, struct stack *s) {
    if (s-> top == s->size) {
        printf("Can't push; stack overflow.\n");
    } else {
        s->top = s->top + 1;
        s->items[s->top] = x;
        printf("Item pushed sucessfully.\n");
    }
}

/* Return the stack size, assuming it's 0-indexed. */
int size(struct stack *s) {
    return s->top + 1;
}

/* Returns 1 if the stack is empty; returns 0 otherwise. */
int isEmpty(struct stack *s) {
    return s->top == -1; // Could be also done as size(s) == 0
}

/* 
    Pops an element out of the stack (first-out) and returns it.
    Error value: -99999. (I understand this is not a good practice, but I don't know another way to do it)
*/
int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Cannot pop; stack underflow.\n");
        return -99999;
    } else {
        s->top--;
        return s->items[s->top + 1];
    }
}

int main() {
    /* Getting user input - array size */
    int size;
    printf("Insert the stack size: ");
    scanf("%d", &size);

    struct stack *s = newStack(size); /* Initializing stack */

    int option = -1; /* Current user input option */

    int item; /* Item to be pushed if the user chooses to do so */

    /* User input loop */
    while (option != 0) {
        printf("What would you like to do?\n");
        printf("0 - Quit\n");
        printf("1 - Insert item into stack\n");
        printf("2 - Pop element out of the stack\n");
        fflush(stdin);
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Insert an item to insert: ");
                scanf("%d", &item);
                push(item, s);
                break;

            case 2:
                item = pop(s);
                if (item != -99999) {
                    printf("The item that has been popped is: %d\n", item);

                }
                break;

            case 0:
                printf("Thanks for your time! :)\n");
                break;

            default:
                printf("Please insert a valid option..\n");
                break;
        }
    }


    return 0;
}