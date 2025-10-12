class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                int val = 0;
                bool ok = true;
                for (auto &p : freq) {
                    if (val == 0) val = p.second;
                    else if (p.second != val) {
                        ok = false;
                        break;
                    }
                }

                if (ok) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
