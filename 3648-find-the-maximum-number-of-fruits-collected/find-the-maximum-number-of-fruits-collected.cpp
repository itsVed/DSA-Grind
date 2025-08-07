class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int c2collect(int i, int j, vector<vector<int>> &fruits){

        if(i >= n || j < 0 || j >= n){
            return 0;
        }

        if(i > j || i == j){
            return 0;
        }

        if(i == n - 1 and j == n - 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int left = fruits[i][j] + c2collect(i + 1, j - 1, fruits);
        int right = fruits[i][j] + c2collect(i + 1, j, fruits);
        int diagonal = fruits[i][j] + c2collect(i + 1, j + 1, fruits);


        return dp[i][j] = max({left, right, diagonal});
    }

    int c3collect(int i, int j, vector<vector<int>> &fruits){

        if(i >= n || j < 0 || j >= n){
            return 0;
        }

        if(i == n - 1 and j == n - 1) return 0;

        if(i < j || i == j){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int left = fruits[i][j] + c3collect(i - 1, j + 1, fruits);
        int right = fruits[i][j] + c3collect(i, j + 1, fruits);
        int diagonal = fruits[i][j] + c3collect(i + 1, j + 1, fruits);


        return dp[i][j] = max({left, right, diagonal});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int c1 = 0;
        n = fruits.size();
        dp.resize(n, vector<int> (n, -1));

        for(int i=0; i < n; i++){
            c1 += fruits[i][i];
        }

        int c2 = c2collect(0, n - 1, fruits);
        int c3 = c3collect(n - 1, 0, fruits);

        return c1 + c2 + c3;
    }
};