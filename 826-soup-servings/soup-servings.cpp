class Solution {
public:
    vector<vector<double>> dp;

    double f(int A, int B){
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (dp[A][B] != -1) return dp[A][B];

        double op1 = f(A - 100, B);
        double op2 = f(A - 75, B - 25);
        double op3 = f(A - 50, B - 50);
        double op4 = f(A - 25, B - 75);
        
        double ans = 0.25 * (op1 + op2 + op3 + op4);
        return dp[A][B] = ans;
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        
        dp.assign(n + 1, vector<double>(n + 1, -1));
        return f(n, n);
    }
};