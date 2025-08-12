class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    long long powerInt(int base, int exp, int limit) {
        long long res = 1;
        while (exp--) {
            res *= base;
            if (res > limit) break;
        }
        return res;
    }

    int f(int i, int n, int x) {
        if (n == 0) return 1;   
        if (n < 0) return 0;    

        if(dp[i][n] != -1) return dp[i][n];

        long long k = powerInt(i, x, n);
        if (k > n) return 0;   

        int take = f(i + 1, n - k, x);
        int skip = f(i + 1, n, x); 

        return dp[i][n] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 2, vector<int>(n + 1, -1));
        return f(1, n, x); 
    }
};