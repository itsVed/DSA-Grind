class Solution {
public:
    bool hasSameDigits(string s) {
        string newstr = "";

        while(s.length() != 2){

            for(int i=1; i < s.length(); i++){
                newstr += ((s[i] - '0' + s[i - 1] - '0') % 10);
            }

            s = newstr;
            newstr = "";
        }

        if(s[0] == s[1]) return true;

        return false;
    }
};