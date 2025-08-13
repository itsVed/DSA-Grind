class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int f(int i, int buy, vector<int> &prices){

        if(i >= n){
            return 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        // buying and selling have 2 options so we take max of both

        if(buy){
            profit = max( -prices[i] + f(i + 1, 0, prices), 0 + f(i + 1, 1, prices)); // buying
        }
        else{
            profit = max( prices[i] + f(i + 2, 1, prices), 0 + f(i + 1, 0, prices)); // selling
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        dp.assign(n, vector<int>(2, -1));
        return f(0, 1, prices);
    }
};