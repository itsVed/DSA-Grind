class Solution {
public:

    int solve(int idx, const vector<int> &cost, vector<int> &dp) {
        if (idx >= cost.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        return dp[idx] = cost[idx] + min(solve(idx + 1, cost, dp), solve(idx + 2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};
