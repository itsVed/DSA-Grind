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
    vector<int> arr;

    void inorder(TreeNode *root){

        if(root == NULL) return;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);

    }

    TreeNode *build(int l, int r){

        if(l > r) return NULL;

        int mid = (l + r) / 2;

        TreeNode *node = new TreeNode(arr[mid]);

        node->left = build(l, mid - 1);
        node->right = build(mid + 1, r);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        
        inorder(root);

        return build(0, arr.size() - 1);
    }   
};