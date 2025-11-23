class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int sum_mod, vector<int> &nums) {
        if (i == nums.size())
            return (sum_mod == 0 ? 0 : INT_MIN);   // valid only if divisible by 3

        if (dp[i][sum_mod] != -1)
            return dp[i][sum_mod];

        // Option 1: include current number
        int take = nums[i] + solve(i + 1, (sum_mod + nums[i]) % 3, nums);

        // Option 2: skip current number
        int skip = solve(i + 1, sum_mod, nums);

        return dp[i][sum_mod] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        dp.assign(nums.size(), vector<int>(3, -1));
        int ans = solve(0, 0, nums);
        return (ans < 0 ? 0 : ans);
    }
};
