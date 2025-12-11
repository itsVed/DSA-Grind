class Solution {
public:
    vector<bool> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        dp.resize(n + 1, false);
        dp[0] = true;

        for(int i=1; i <= n; i++){
            for(string &w : wordDict){
                int st = i - w.length();

                if(st >= 0 and dp[st] and s.substr(st, w.length()) == w){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};