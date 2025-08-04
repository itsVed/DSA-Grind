class Solution {
public:

    int f(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){
        if(i == m - 1 and j == n - 1){
            return 1;
        }

        if(i >= m  || j >= n){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int right = f(i, j + 1, grid, m, n, dp);
        int down = f(i + 1, j, grid, m, n, dp);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        
        if(m == 1 and n == 1) return 1;

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        vector<vector<int>> grid(m, vector<int> (n, 0));
        
        f(0, 0, grid, m, n, dp);

        return dp[0][0];
    }
};