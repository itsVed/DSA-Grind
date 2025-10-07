class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length() - 1;

        auto ispalindrome = [&](int i, int j, string s){
            while(i < j){
                if(s[i] != s[j]){
                    return false;
                }
                i++;
                j--;
            }

            return true;
        };

        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                if(ispalindrome(i, j-1, s) || ispalindrome(i+1, j, s)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};