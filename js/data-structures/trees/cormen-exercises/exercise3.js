/* 
    Write an O(n)-time nonrecursive procedure that, given an n-node binary tree, prints out the key of each node in the tree. 
    Use a stack as an auxiliary data structure.
*/

import { Stack } from "../../stack/stack";

class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

/**
 * @param {TreeNode} node 
 */
function printOutAllKeysInorder(node) {
    let currentNode = node;
    let s = new Stack();
    while (!s.isEmpty() || currentNode != null) {
        while (currentNode != null) {
            s.push(currentNode);
            currentNode = currentNode.left;
        }        
        currentNode = s.top();
        s.pop();
        console.log(currentNode.value);
        currentNode = currentNode.right
    }
}

let root = new TreeNode(1);
root.right = new TreeNode(2);
root.left = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
printOutAllKeysInorder(root);