class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> pre(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (s[i - 1] == 'Y' ? 1 : 0);
        }

        int totalY = pre[n];
        int ans = 0, minPenalty = INT_MAX;

        for (int i = 0; i <= n; i++) {
            int penalty = (i - pre[i]) + (totalY - pre[i]);
            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};