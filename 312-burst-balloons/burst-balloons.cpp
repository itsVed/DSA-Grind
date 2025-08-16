class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int j, vector<int>& nums) {
        if (i > j) return 0;

        if(dp[i][j] != - 1) return dp[i][j];

        int maxi = 0;
        for (int ind = i; ind <= j; ind++) {
            int coins = nums[i-1] * nums[ind] * nums[j+1] + f(i, ind-1, nums) + f(ind+1, j, nums);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1); 
        nums.push_back(1);
        dp.assign(n+2, vector<int> (n+2, -1));

        return f(1, n, nums);     
    }
};