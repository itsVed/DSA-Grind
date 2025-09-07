/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null";

        string s = "";

        queue<TreeNode*> q;
        q.push(root);

       while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "null,";
            }
        }

       return s;
    }

    TreeNode* deserialize(string data) {
        if (data == "null,")
            return nullptr;

        stringstream ss(data);
        string val;
        getline(ss, val, ',');

        if (val == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, val, ',')) {
                if (val != "null") {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }

            if (getline(ss, val, ',')) {
                if (val != "null") {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));