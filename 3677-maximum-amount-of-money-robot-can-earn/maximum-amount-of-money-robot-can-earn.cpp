class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        for (int k = 0; k < 3; k++) {
            if (coins[m-1][n-1] >= 0) dp[m-1][n-1][k] = coins[m-1][n-1];
            else dp[m-1][n-1][k] = (k < 2 ? 0 : coins[m-1][n-1]);
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;

                for (int used = 0; used < 3; used++) {
                    int bestNext = -1e9;

                    if (i + 1 < m) bestNext = max(bestNext, dp[i+1][j][used]);
                    if (j + 1 < n) bestNext = max(bestNext, dp[i][j+1][used]);

                    int ans = coins[i][j] + bestNext;

                    if (coins[i][j] < 0 && used < 2) {
                        int bestNeutral = -1e9;

                        if (i + 1 < m) bestNeutral = max(bestNeutral, dp[i+1][j][used+1]);
                        if (j + 1 < n) bestNeutral = max(bestNeutral, dp[i][j+1][used+1]);

                        ans = max(ans, bestNeutral);
                    }

                    dp[i][j][used] = ans;
                }
            }
        }

        return dp[0][0][0];
    }
};