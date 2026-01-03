class Solution {
public:
    int MOD = 1e9 + 7;
    vector<string> states = {
        "RYR", "RYG", "RGR", "RGY",
        "YRY", "YRG", "YGR", "YGY",
        "GRY", "GRG", "GYR", "GYG"
    };

    vector<vector<long long>> dp;

    long long solve(int n, int idx) {
        if (n == 0) return 1;

        if (dp[n][idx] != -1)
            return dp[n][idx];

        long long result = 0;
        string prev = states[idx];

        for (int j = 0; j < 12; j++) {
            string curr = states[j];

            bool valid = true;
            for (int k = 0; k < 3; k++) {
                if (curr[k] == prev[k]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result = (result + solve(n - 1, j)) % MOD;
            }
        }

        return dp[n][idx] = result;
    }

    int numOfWays(int n) {
        dp.assign(n, vector<long long>(12, -1));

        long long result = 0;
        
        for (int i = 0; i < 12; i++) {
            result = (result + solve(n - 1, i)) % MOD;
        }

        return result;
    }
};
