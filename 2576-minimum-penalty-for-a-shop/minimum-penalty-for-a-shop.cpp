// class Solution {
// public:
//     int bestClosingTime(string s) {
//         int n = s.size();
//         vector<int> pre(n + 1, 0);

//         // pre[i] = number of 'Y' in s[0..i-1]
//         for (int i = 1; i <= n; i++) {
//             pre[i] = pre[i - 1] + (s[i - 1] == 'Y' ? 1 : 0);
//         }

//         int totalY = pre[n];
//         int ans = 0, minPenalty = INT_MAX;

//         for (int i = 0; i <= n; i++) {
//             // customers before closing (0..i-1) are penalized if they are 'N'
//             int penalty = (i - pre[i])  // 'N's before closing
//                         + (totalY - pre[i]); // 'Y's after closing
//             if (penalty < minPenalty) {
//                 minPenalty = penalty;
//                 ans = i;
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> pre(n + 1, 0);

        for(int i=1; i <= n; i++){
            pre[i] = pre[i - 1] + (s[i - 1] == 'Y' ? 1 : 0);
        }

        
        int idx = -1;
        int minpen = INT_MAX;

        for(int cust = 0; cust <= n; cust++){
            // cust is total customer 
            // penalty = previous 'N' + after 'Y'
            int pen = (cust - pre[cust]) + (pre[n] - pre[cust]);

            if(pen < minpen){
                minpen = pen;
                idx = cust;
            }
        }

        return idx;
    }
};