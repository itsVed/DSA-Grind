#define MOD 1000000007
using lli = long long;

class Solution {
public:
    vector<vector<lli>> dp;
    string corridor;
    lli n;

    lli solve(lli idx, lli s) {
        // Base case: last index
        if (idx == n - 1) {
            return (s + (corridor[idx] == 'S') == 2);
        }

        if (dp[idx][s] != -1) return dp[idx][s];

        lli ns = s + (corridor[idx] == 'S');

        // Invalid if more than 2 seats
        if (ns > 2) return dp[idx][s] = 0;

        lli ways = 0;

        // Option 1: continue current segment
        ways = (ways + solve(idx + 1, ns)) % MOD;

        // Option 2: cut if exactly 2 seats
        if (ns == 2) {
            ways = (ways + solve(idx + 1, 0)) % MOD;
        }

        return dp[idx][s] = ways;
    }

    int numberOfWays(string s) {
        corridor = s;
        n = corridor.size();
        dp.assign(n, vector<lli>(3, -1));

        return (int) solve(0, 0);
    }
};
