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
    void insert(TreeNode *root, TreeNode *node){
        if(!root) return;

        if(root->val < node->val){
            if(root->right) insert(root->right, node);
            else{
                root->right = node;
                return;
            }
        }
        else{
            if(root->left) insert(root->left, node);
            else{
                root->left = node;
                return;
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode *node = new TreeNode(val);

        if(!root) return node;

        insert(root, node);

        return root;
    }
};