class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;

        for (int k = 0; k < m + n - 1; k++) {
            vector<int> temp;

            for (int i = 0; i < m; i++) {
                int j = k - i;
                if (j >= 0 && j < n) {
                    temp.push_back(mat[i][j]);
                }
            }

            if (k % 2 == 0) reverse(temp.begin(), temp.end());

            for (int x : temp)
                ans.push_back(x);
        }

        return ans;
    }
};