class Solution {
public:
    vector<long long> dp;

    long long solve(int i, vector<int> &prices){
        if(i + 1 == prices.size()){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        if(prices[i + 1] + 1 == prices[i]){
            return dp[i] = 1 + solve(i + 1, prices);
        }

        return dp[i] = 0;
    }

    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = n;
        dp.resize(n, -1);

        for(int i=0; i < n; i++){
            ans += solve(i, prices);
        }

        return ans;
    }
};