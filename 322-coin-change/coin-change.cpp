class Solution {
public:

    int f(int i, vector<int> & coin, int amount, vector<vector<int>> &dp){
        if (amount == 0) return 0;
        
        if(i == 0){
            if(amount % coin[i] == 0) return amount/coin[i];
            else return 1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 1e9;
        if(coin[i] <= amount) take = 1 + f(i, coin, amount - coin[i], dp);

        int skip = 0 + f(i - 1, coin, amount, dp);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        int ans = f(coins.size() - 1, coins, amount, dp);
        
        return ans == 1e9 ? -1 : ans;
    }
};