class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int cnt = 0;

        vector<bool> alreadysorted(n - 1, false);

        for (int i = 0; i < m; i++) {
            bool flag = true;

            for (int j = 0; j < n - 1; j++) {
                if (!alreadysorted[j] && strs[j][i] > strs[j + 1][i]) {
                    flag = false;
                    cnt++;
                    break;
                }
            }

            if (!flag) continue;

            for (int j = 0; j < n - 1; j++) {
                alreadysorted[j] =  alreadysorted[j] || strs[j][i] < strs[j + 1][i];
            }
        }

        return cnt;
    }
};
