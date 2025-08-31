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
    int left =  INT_MAX;
    int right = INT_MIN;

    void leftNode(TreeNode *root, int row, int col){
        if(!root) return;

        left = min(left, col);
        right = max(right, col);

        if(root->left) leftNode(root->left, row + 1, col - 1);
        if(root->right) leftNode(root->right, row + 1, col + 1);
    }

    void dfs(TreeNode *root, int row, int col, vector<vector<pair<int,int>>> &values){
        if(!root) return;

        values[col - left].push_back({row, root->val});
        dfs(root->left, row + 1, col - 1, values);
        dfs(root->right, row + 1, col + 1, values);
    }
     
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        leftNode(root, 0, 0);
        int total = right - left + 1;
        vector<vector<pair<int,int>>> values(total);

        dfs(root, 0, 0, values);

        for(auto val: values){

            sort(val.begin(), val.end(), [](auto &a, auto &b){
                if(a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });

            vector<int> a;
            for(auto p : val){
                a.push_back(p.second);
            }

            ans.push_back(a);
        }

        return ans;
    }
};