class Solution {
public:
    bool check(int i, int j, string &s) {
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        return i >= j;
    }
    
    vector<int> dp;

    int minCut(string s) {
        int n = s.size();

        dp.assign(n + 1, - 1);
        
        dp[n] = 0;

        for(int i=n-1; i >=0; i--){
            int mini = 1e9;

            for(int j=i; j < n; j++){
            
                if(check(i, j, s)){
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }

            }

            dp[i] = mini;
        }


        return dp[0] - 1;
    }
};