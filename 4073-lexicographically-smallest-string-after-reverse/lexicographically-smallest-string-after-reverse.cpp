class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;

        for(int i=1; i <= s.length(); i++){
            string test = s;
            reverse(test.begin(), test.begin() + i);

            if(test < ans) ans = test;
        }

        for(int i=1; i <= s.length(); i++){
            string test = s;
            reverse(test.end() - i, test.end());

            if(test < ans) ans = test;
        }

        return ans;
    }
};