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
    bool checkTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        
        int l = root->left ? root->left->val : 0;
        int r = root->right ? root->right->val : 0;
        
        if(root->val != l + r){
            return false;
        }
    
        return checkTree(root->left) and checkTree(root->right);
    }
};