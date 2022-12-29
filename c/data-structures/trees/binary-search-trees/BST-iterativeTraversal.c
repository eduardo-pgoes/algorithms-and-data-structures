#include <stdio.h>
#include <stdlib.h>

#pragma region BSTNode
#include <stdio.h>
#include <stdlib.h>

#pragma region BSTNode

/* Tree function prototypes*/
struct BSTNode* insertIntoBSTree(struct BSTNode*, int);
struct BSTNode* newBSTNode(int);
void inorderTraversal(struct BSTNode*);

/**
 * \struct Represents a binary search tree node.
*/

struct BSTNode {
    int data; /* Node data */
    struct BSTNode *left; /* Pointer to the binary search tree's left subtree */  
    struct BSTNode *right; /* Pointer to the binary search tree's right subtree */
};

/**
 * \brief Inserts a new value (together with its node) to a binary search tree.
 * \param root Root of the binary search tree.
 * \param data Value to be inserted in the binary search tree.
 * \return Unchanged pointer to the root of the binary search tree.
*/
struct BSTNode* insertIntoBSTree(struct BSTNode *root, int data) {
    if (root == NULL) {
        return newBSTNode(data);
    }

    if (data < root->data) {
        root->left = insertIntoBSTree(root->left, data);
    } else if (data > root->data) {
        root->right = insertIntoBSTree(root->right, data);
    }

    return root;
}

/**
 * \brief Creates a new binary search tree node.
 * \param data The data to be inserted into the node.
 * \returns Pointer to the binary search tree node.
*/
struct BSTNode* newBSTNode(int data) {
    struct BSTNode *temp = malloc(sizeof *temp);

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

#pragma endregion BSTNode

#pragma region Stack

struct stackNode {
    struct stackNode *next;
    struct BSTNode *data;
};

/* Stack function prototypes */
int isEmpty(struct stackNode*);
int push(struct stackNode**, struct BSTNode*) ;
struct BSTNode* pop(struct stackNode**);
struct stackNode* newStackNode(struct BSTNode*);

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
int push(struct stackNode **head, struct BSTNode* data) {
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

/**
 * \brief Creates a new stack node.
 * \param data The data you want to insert in the new node.
 * \return Pointer to the stack node.
*/
struct stackNode* newStackNode(struct BSTNode *data) {
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
struct BSTNode* pop(struct stackNode **head) {
    struct stackNode *temp;
    struct BSTNode *res; // Result we'll return

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

#pragma region iterativeAlgorithms

void iterativeInorderTraversal(struct BSTNode *root) {
    // Base case
    if (root == NULL) return;

    struct BSTNode *current = root;
    struct stackNode *stack = NULL;
    int done = 0;

    while (!done) {
        // Go all the way to the left and push the nodes to the stack
        if (current != NULL) {
            push(&stack, current);
            current = current->left;
        } else {
            if (!isEmpty(stack)) {
                current = pop(&stack); // Get the latest visited left node...
                printf("%d ", current->data);
                // Now, it's time to go to the right.
                current = current->right;
            } else {
                // No more nodes to go through.
                done = 1;
            }
        }
    }
}

void iterativePreorderTraversal(struct BSTNode *root) {
    // Base case
    if (root == NULL) return;

    struct stackNode *stack;
    struct BSTNode *current;
    push(&stack, root);

    while (!isEmpty(stack)) {
        current = pop(&stack);

        if (isEmpty(stack)) {
            return;
        }
        
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(&stack, current->right);
        } 

        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

#pragma endregion iterativeAlgorithms

int main() {
    struct BSTNode* root = NULL;
    root = insertIntoBSTree(root, 3);
    insertIntoBSTree(root, 3);
    insertIntoBSTree(root, 2);
    insertIntoBSTree(root, 4);
    insertIntoBSTree(root, 7);
    insertIntoBSTree(root, 6);
    insertIntoBSTree(root, 8);
    iterativePreorderTraversal(root);

    return 0;
}