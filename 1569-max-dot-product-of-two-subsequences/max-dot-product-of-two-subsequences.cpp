class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i == m || j == n){
            return -1e9;
        }

        if(dp[i][j] != -1e9){
            return dp[i][j];
        }

        int val = nums1[i] * nums2[j];
        int take_i_j = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1);
        int take_i = solve(nums1, nums2, i + 1, j);
        int take_j = solve(nums1, nums2, i, j + 1);

        return dp[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        dp.assign(m + 1, vector<int>(n + 1, -1e9));
        
        return solve(nums1, nums2, 0, 0);
    }
};