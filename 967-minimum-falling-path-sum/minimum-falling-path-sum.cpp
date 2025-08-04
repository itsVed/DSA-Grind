class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        for(int i=0;i < col; i++){
            dp[0][i] = matrix[0][i]; 
        }

        for(int i=1; i < row; i++){
            for(int j=0; j < col; j++){

                int d = matrix[i][j] + dp[i-1][j];
                int l = matrix[i][j];

                if(j - 1 >= 0) l += dp[i-1][j-1];
                else l += 1e9;

                int r = matrix[i][j];

                if(j + 1 < col) r += dp[i-1][j+1];
                else r += 1e9;

                dp[i][j] = min({d, l, r});

            }
        }

        int ans = dp[row - 1][0];
        for (int j = 1; j < col; j++) {
            ans = min(ans, dp[row - 1][j]);
        }

        return ans;
    }
};
