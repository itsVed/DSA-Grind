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
    priority_queue<int, vector<int>, greater<int>> pq;
    
    void traverse(TreeNode *root){
        if(!root) return;

        pq.push(root->val);

        if(root->left) traverse(root->left);
        if(root->right) traverse(root->right);
        
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        int ans = 0;
        traverse(root);

        while(k > 0 and !pq.empty()){
            ans = pq.top();
            pq.pop();
            k--;
        }

        return ans;
    }
};