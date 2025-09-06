/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;

    void node(TreeNode *root){
        if(!root) return;

        count++;
        node(root->left);
        node(root->right);
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        node(root);
        
        return count;
    }
};