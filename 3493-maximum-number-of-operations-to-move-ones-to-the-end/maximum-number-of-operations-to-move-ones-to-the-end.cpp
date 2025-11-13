class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();

        int countone = 0;
        int ans = 0;

        for(int i=0; i < n; i++){
            if(i == n - 1 and s[i] == '0' || s[i] == '0' and s[i + 1] == '1'){
                ans += countone;
            }
            else if(s[i] == '1'){
                countone++;
            }
        }

        return ans;
    }
};