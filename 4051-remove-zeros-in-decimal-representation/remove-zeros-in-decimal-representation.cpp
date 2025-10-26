class Solution {
public:
    long long removeZeros(long long n) {
        long long ans;
        string s = to_string(n);
        string a = "";

        for(auto ch : s){
            if(ch != '0') a += ch;
        }
        
        ans = stoll(a);

        return ans;
    }
};