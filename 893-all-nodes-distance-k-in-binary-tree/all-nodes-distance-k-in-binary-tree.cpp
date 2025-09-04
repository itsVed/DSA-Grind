/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent){
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }

            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode *> parent;
        markparent(root, parent);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        int level = 0;
        visited[target] = true;

        while(!q.empty()){
            
            int n = q.size();
            if(level == k) break;
            level++;

            for(int i=0; i < n; i++){
                TreeNode *node = q.front();
                q.pop();

                if(node->left and !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right and !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent.count(node) and !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            ans.push_back(node->val);
        }

        return ans;
    }
};