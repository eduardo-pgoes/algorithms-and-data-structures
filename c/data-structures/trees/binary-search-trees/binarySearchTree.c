#include <stdio.h>
#include <stdlib.h>

#pragma region BSTNode

/* Tree function prototypes*/
struct BSTNode* insertIntoBSTree(struct BSTNode*, int);
struct BSTNode* newBSTNode(int);
void inorderTraversal(struct BSTNode*);
void preorderTraversal(struct BSTNode*);
void postorderTraversal(struct BSTNode*);
void deallocateTree(struct BSTNode*);
struct BSTNode* searchInBSTree(struct BSTNode*, int);
struct BSTNode* removeFromBSTree(struct BSTNode*, int);

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

/**
 * \brief Goes through a tree's inorder traversal recursively.
 * \param root Pointer to the tree's root.
*/
void inorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

/**
 * \brief Goes through a tree's postorder traversal recursively.
 * \param root Pointer to the tree's root.
*/
void postorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    } 

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

/**
 * \brief Goes through a tree's preorder traversal recursively.
 * \param root Pointer to the tree's root.
*/
void preorderTraversal(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

/**
 * \brief Deallocates all the memory a tree occupies.
 * \param root Pointer to the tree root.
*/
void deallocateTree(struct BSTNode *root) {
    if (root == NULL) return;
    deallocateTree(root->left);
    deallocateTree(root->right);
    free(root);
}


/**
 * \brief Function that removes a node from a binary search tree root.
 * @param raiz Pointer to the binary search tree root.
 * @param data Data you want to remove from the tree.
 * @returns Pointer to the new tree root.
*/
struct BSTNode* removeFromBSTree(struct BSTNode *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = removeFromBSTree(root->left, data);
    } else if (data > root->data) {
        root->right = removeFromBSTree(root->right, data);
    } else {
        // Base case - root with no children
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            return NULL;
        } else if (root->left == NULL) {
            struct BSTNode *temp = root->right;
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode *temp = root->left;
            return temp;
        } else {
            // Following the instructions for nodes with two children
            struct BSTNode *parent, *temp;
            parent = root;
            temp = root->left;
            while(temp->right != NULL){  //Looking for the biggest leaf in the left
                parent = temp;
                temp = temp->right;
            }
            root->data = temp->data;
            if(parent->data == root->data){ 
                parent->left = temp->left;
            } else {
                parent->right = temp->left;
            }
        }
    }
    return root;
}

#pragma endregion BSTNode

int main() {
    struct BSTNode* root = NULL;
    root = insertIntoBSTree(root, 3);
    insertIntoBSTree(root, 3);
    insertIntoBSTree(root, 2);
    insertIntoBSTree(root, 4);
    insertIntoBSTree(root, 7);
    insertIntoBSTree(root, 6);
    insertIntoBSTree(root, 8);
    inorderTraversal(root);

    return 0;
}