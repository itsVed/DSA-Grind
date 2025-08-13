class Solution {
public:
    
    int n;
    vector<vector<vector<int>>> dp;

    int f(int i, int k, int buy, vector<int> &prices){
        if(k == 0 || i == n) return 0;

        int profit = 0;

        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        if(buy){
            profit = max(-prices[i] + f(i + 1, k, 0, prices), f(i + 1, k, 1, prices));
        }
        else{
            profit = max(+prices[i] + f(i + 1, k - 1, 1, prices), f(i + 1, k, 0, prices));
        }

        return dp[i][buy][k] = profit;

    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, k, 1, prices);
    }
};