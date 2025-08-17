class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        int n = p.size();
        long long base = 0;

        for (int i = 0; i < n; i++) {
            base += 1LL * s[i] * p[i];
        }

        vector<long long> A(n), B(n);
        
        for (int i = 0; i < n; i++) {
            A[i] = -(1LL * s[i] * p[i]);
            B[i] = (1 - s[i]) * 1LL * p[i];
        }

        vector<long long> prefixA(n), prefixB(n);
        prefixA[0] = A[0];
        prefixB[0] = B[0];

        for (int i = 1; i < n; i++) {
            prefixA[i] = prefixA[i-1] + A[i];
            prefixB[i] = prefixB[i-1] + B[i];
        }

        int half = k/2;
        long long maxGain = 0;

        for (int i = 0; i + k <= n; i++) {
            long long part1 = prefixA[i + half - 1] - (i > 0 ? prefixA[i - 1] : 0);
            long long part2 = prefixB[i + k - 1] - prefixB[i + half - 1];
            long long gain = part1 + part2;
            maxGain = max(maxGain, gain);
        }

        return base + maxGain;
    }
};
