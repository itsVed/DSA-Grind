class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string ans = "1";

        for (int i = 2; i <= n; i++) {
            string demo = ans;
            string fin = "";

            for (int j = 0; j < demo.length(); ) {
                char ch = demo[j];
                int count = 0;

                while (j < demo.length() && demo[j] == ch) {
                    count++;
                    j++;
                }

                fin += to_string(count) + ch;
            }

            ans = fin;
        }

        return ans;
    }
};
