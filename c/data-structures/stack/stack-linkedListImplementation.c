#include <stdio.h>
#include <stdlib.h>

#pragma region Stack

struct stackNode {
    struct stackNode *next;
    int data;
};

/* Stack function prototypes */
int isEmpty(struct stackNode*);
int push(struct stackNode**, int) ;
int pop(struct stackNode**);
struct stackNode* newStackNode(int);

/**
 * \brief Tells you if the stack is empty or not.
 * \param s Stack
 * \returns True or false (1, 0)
*/
int isEmpty(struct stackNode *s) {
    return (s == NULL) ? 1 : 0;
}

/**
 * \brief Pushes a new element into the stack.
 * \param s The stack you want to push this new item into
 * \param data The data you want to push into the stack
*/
int push(struct stackNode **head, int data) {
    struct stackNode *ptr = newStackNode(data);

    // Couldn't allocate space for the next entry
    if (ptr == NULL) {
        printf("Stack overflow.");
        return 0;
    }

    if (isEmpty(*head)) {
        ptr->data = data;
        ptr->next = NULL;
        *head = ptr;
        return 1;
    }

    ptr->data = data;
    // LIFO -> new stack's next pointer should point to the old stack, since it's at the top
    ptr->next = *head;
    *head = ptr;

    return 1;
}

struct stackNode* newStackNode(int data) {
    struct stackNode *s = malloc(sizeof *s);
    s->data = data;
    s->next = NULL;
    return s;
}

/**
 * \brief Pops an element out of the stack
 * \param s Stack
 * \return Element out of stack (LIFO)
*/
int pop(struct stackNode **head) {
    struct stackNode *temp;
    int res; // Result we'll return

    if (isEmpty(*head)) {
        printf("Stack empty.");
        return 0;
    }

    temp = *head;
    res = temp->data;
    (*head) = (*head)->next;

    free(temp);

    return res;
}

#pragma endregion Stack

int main() {
    struct stackNode *s = newStackNode(1);
    push(&s, 3);
    push(&s, 4);

    int entry = pop(&s);
    printf("%d ", entry);
    entry = pop(&s);    
    printf("%d ", entry);
    entry = pop(&s);    
    printf("%d", entry);
}