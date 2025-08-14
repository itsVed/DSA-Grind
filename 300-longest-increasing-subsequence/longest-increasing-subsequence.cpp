class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int f(int i, int prev, vector<int> &nums){
        
        if(i >= n) return 0;

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + f(i + 1, i, nums);
        }

        int skip = f(i + 1, prev, nums);

        return dp[i][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));

        return f(0, -1, nums);
    }
};