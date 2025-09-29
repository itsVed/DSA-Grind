class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int> &val){
        if(i + 1 == j) return 0;
        
        int ans = INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        for(int k=i+1; k < j; k++){
            ans = min(ans, val[i] * val[j] * val[k] + solve(i, k, val) + solve(k, j, val));
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        // i understand this is a problem of DP
        // ig standard dp
        // check all the possibilities with n - 2 pairs

        int n = values.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1, values);

    }
};