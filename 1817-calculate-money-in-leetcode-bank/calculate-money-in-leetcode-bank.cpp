class Solution {
public:
    int totalMoney(int n) {
        int k = 1;
        int ans = 0;

        for(int i=1; i <= n / 7 + 1; i++){
            for(int j = i; k <= n and j < i + 7; j++, k++){
                ans += j;
            }
        }

        return ans;
    }
};