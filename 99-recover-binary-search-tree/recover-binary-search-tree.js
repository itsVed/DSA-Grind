/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */

function inorder(root, arr){
    if(root == null) return;

    inorder(root.left, arr);
    arr.push(root.val);
    inorder(root.right, arr);
}

function change(root, arr, idx) {
    if (root == null) return;

    change(root.left, arr, idx);

    root.val = arr[idx.i];  
    idx.i++;             

    change(root.right, arr, idx);
}

var recoverTree = function(root) {
    let arr = [];
    inorder(root, arr);

    arr.sort((a, b) => a - b);

    let idx = {i : 0};
    change(root, arr, idx);
};