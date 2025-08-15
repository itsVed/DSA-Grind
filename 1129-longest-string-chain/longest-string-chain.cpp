class Solution {
public:

    bool compare(string &s1, string &s2){

        if(s1.length() != s2.length() + 1) return false;

        int i = 0;
        int j = 0;

        while(i < s1.length()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        if(i == s1.length() and j == s2.length()) return true;
        else return false;
    }

    bool static check(string &s1, string &s2){
        return s1.length() < s2.length();
    } 

    int longestStrChain(vector<string>& words) {

        int n = words.size();
        
        sort(words.begin(), words.end(), check);

        int maxi = 1;
        vector<int> dp(n, 1);

        for(int i=0; i < n; i++){
            for(int prev = 0; prev < i; prev++){

                if(compare(words[i], words[prev]) and 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }

            maxi = max(dp[i], maxi);
        }
    
        return maxi;
    }
};