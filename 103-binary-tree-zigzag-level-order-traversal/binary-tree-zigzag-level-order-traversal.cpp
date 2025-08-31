class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = false; 

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            if (flag) {
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);

            flag = !flag;
        }

        return ans;
    }
};
