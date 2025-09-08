class Solution {
public:
    int ans = -1;
    int temp;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (root->val > temp) {
            if (ans == -1 || root->val < ans) {
                ans = root->val;
            }
        }

        inorder(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        temp = root->val;
        inorder(root);

        return ans;
    }
};
