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

    void traverse(TreeNode *root, vector<TreeNode*> &ans){
        if(!root) return;

        ans.push_back(root);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }


    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        if(!root) return;

        traverse(root, ans);
        TreeNode *temp = root;

        for(int i=1; i < ans.size(); i++){
            temp->right = ans[i];
            temp->left = NULL;
            temp = temp->right;
        }

        temp->right = NULL;
    }
};