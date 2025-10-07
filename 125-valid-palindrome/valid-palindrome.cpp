class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";

        auto checkpal = [&](int i, int j, string s){
            while(i < j){
                if(s[i] != s[j]){
                    return false;
                }
                i++;
                j--;
            }

            return true;
        };

        for(int i=0; i < s.length(); i++){
            if(s[i] <= 'z' and s[i] >= 'a'){
                a += s[i];
            }
            else if(s[i] <= 'Z' and s[i] >= 'A'){
                a += tolower(s[i]);
            }
            else if(s[i] >= '0' and s[i] <= '9'){
                a += s[i];
            }
        }
        cout<<a<<endl;
        return checkpal(0, a.length() - 1, a);
    }
};