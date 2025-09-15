function inorder(node, arr) {
    if (!node) return;
    inorder(node.left, arr);
    arr.push(node.val);
    inorder(node.right, arr);
}

var BSTIterator = function(root) {
    this.a = [];   
    this.idx = 0;
    inorder(root, this.a);
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    return this.a[this.idx++];
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    return this.idx < this.a.length;
};
