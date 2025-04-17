class Solution {
public:
    int MOD = 1e9 + 7;
    
    int numTilings(int n) {
        if(n == 1 || n == 2) return n;

        vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        // most imp part getting the pattern and draw a formula for that
        // f(n) = 2 * f(n - 1) + f(n - 3)
        // after carefully taking the initial examples you get the pattern
        // and by using it you got the formual
        // its definetly not medium, its should be considered hard
        // asked by Google

        for(int i=4; i <= n; i++){
            dp[i] = ((2 * dp[i - 1]) % MOD + dp[i - 3] % MOD) % MOD;
        } 

        return dp[n];
    }
};