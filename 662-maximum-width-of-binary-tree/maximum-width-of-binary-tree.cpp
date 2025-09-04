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

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long left = q.front().second;
            long long right = q.back().second;

            ans = max(ans, right - left + 1);

            for (int j = 0; j < size; j++) {
                auto [node, idx] = q.front();
                q.pop();

                long long newIdx = idx - left;

                if (node->left) q.push({node->left, newIdx * 2});
                if (node->right) q.push({node->right, newIdx * 2 + 1});
            }
        }
        
        return (int)ans;
    }

};