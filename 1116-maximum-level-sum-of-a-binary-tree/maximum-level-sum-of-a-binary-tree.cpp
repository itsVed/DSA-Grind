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

    int maxLevelSum(TreeNode* root) {
        map<int, int> mp; // {level, sum}

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()){
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();

            mp[level] += node->val;

            if(node->left){
                q.push({node->left, level + 1});
            }

            if(node->right){
                q.push({node->right, level + 1});
            }
        }

        int maxlevel = INT_MAX;
        int maxsum = INT_MIN;

        for(auto it: mp){
            int sum = it.second;
            int level = it.first;

            if (sum > maxsum || (sum == maxsum && level < maxlevel)) {
                maxsum = sum;
                maxlevel = level;
            }
        }

        return maxlevel;
    }
};