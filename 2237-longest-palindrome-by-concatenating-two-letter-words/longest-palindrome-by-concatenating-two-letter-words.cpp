class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> mp;

        for(auto s: words){

            string rev = s;
            reverse(rev.begin(), rev.end());

            if(mp[rev] > 0){
                ans += 4;
                mp[rev]--;
            }
            else{
                mp[s]++;
            }

        }

        for(auto it: mp){
            string s = it.first;

            if(s[0] == s[1] and mp[s] > 0){
                ans += 2;
                break;
            }
        }

        return ans;
    }
};