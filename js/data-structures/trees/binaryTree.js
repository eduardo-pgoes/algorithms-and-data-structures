/*
    Represents a binary tree node.
*/
class BinaryTreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    /**
    * Inserts a node into the binary tree root's left
    * @param {BinaryTreeNode} node
    * @return {void}
    */
    insertIntoLeft(node) {
        this.left = node;
    }

    /**
    * Inserts a node into the binary tree root's right
    * @param {BinaryTreeNode} node
    * @return {void}
    */
    insertIntoRight(node) {
        this.right = node;
    }

    /**
    * Prints the binary tree out recursively inorder
    * @return {void}
    */
    recursiveInorderTraversal() {
        this.recursiveInorderTraversal(this.left);
        console.log(this.value);
        this.recursiveInorderTraversal(this.right);
    }

    /**
    * Prints the binary tree out recursively preorder
    * @return {void}
    */
    recursivePreorderTraversal() {
        console.log(this.value);
        this.recursivePreorderTraversal(this.left);
        this.recursivePreorderTraversal(this.right);
    }

    /**
    * Prints the binary tree out recursively postorder
    * @return {void}
    */
    recursivePostorderTraversal() {
        this.recursivePostorderTraversal(this.left);
        this.recursivePostorderTraversal(this.right);
        console.log(this.value);
    }   
}