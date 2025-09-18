class Solution {
public:
    int M = 1e9 + 7;

    int solve(int i, int parity, int count, vector<int> &nums, vector<vector<vector<int>>> &dp){
        if(i == nums.size()){
            return (parity == -1 ? 0 : 1);
        }
        
        if(dp[i][parity + 1][count] != -1) return dp[i][parity + 1][count];

        int take = 0;

        if(nums[i] % 2 == parity && count < 2){
            take = (solve(i + 1, parity, count + 1, nums, dp)) % M;
        }
        else if(parity != nums[i] % 2){
            take = (solve(i + 1, nums[i] % 2, 1, nums, dp)) % M;
        }

        int skip = (solve(i + 1, parity, count, nums, dp)) % M;

        return dp[i][parity + 1][count] = (take + skip) % M;
    }

    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3, -1)));
        return solve(0, -1, 0, nums, dp); 
    }
};
