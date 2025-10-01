class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string s1, string s2){
        if(i == s1.length()){
            return s2.length() - j;
        }

        if(j == s2.length()){
            return s1.length() - i;
        } 
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return solve(i + 1, j + 1, s1, s2);
        }

        int ans = 1 + min(solve(i + 1, j, s1, s2), min(solve(i, j + 1, s1, s2), solve(i + 1, j + 1, s1, s2)));

        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return solve(0, 0, word1, word2);
    }
};