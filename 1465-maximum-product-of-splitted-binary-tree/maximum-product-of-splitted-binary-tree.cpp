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
    long totalsum = 0;
    long pro = 0;
    int MOD = 1e9 + 7;

    int total(TreeNode *root){
        if(!root) return 0;

        int leftsum = total(root->left);
        int rightsum = total(root->right);
        long sum = root->val + leftsum + rightsum;

        long s2 = totalsum - sum;
        pro = max(pro, s2 * sum);

        return sum;
    }

    int maxProduct(TreeNode* root) {
        totalsum = total(root);
        
        total(root);

        return pro % MOD;
    }
};