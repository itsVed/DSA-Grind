class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int f(int i, int buy, vector<int> &prices, int cap){

        if(i == n || cap == 0){
            return 0;
        }

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;

        // buying and selling have 2 options so we take max of both

        if(buy){
            profit = max( -prices[i] + f(i + 1, 0, prices, cap), 0 + f(i + 1, 1, prices, cap)); // buying
        }
        else{
            profit = max( prices[i] + f(i + 1, 1, prices, cap - 1), 0 + f(i + 1, 0, prices, cap)); // selling
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        dp.assign(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, prices, 2);
    }
};