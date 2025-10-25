class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if (sum > 9 and num == 1)
            return "";

        if (sum < 9) {
            ans += (sum + '0');
            num--;

            while (num > 0) {
                ans += '0';
                num--;
            }

        } 
        else {
            while (sum >= 9 and num > 0) {
                ans += '9';
                sum -= 9;
                num--;
            }

            if (num == 0 and sum != 0)
                return "";

            if (sum) {
                ans += (sum + '0');
                num--;
            };

            if (num) {
                while (num > 0) {
                    ans += '0';
                    num--;
                }
            }
        }

        int score = 0;

        for (int i = 0; i < num; i++) {
            int n = ans[i] - '0';

            score += (n * n);
        }

        return ans;
    }
};