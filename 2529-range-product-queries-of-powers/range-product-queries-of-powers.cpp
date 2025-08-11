class Solution {
public:
    int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> two;
        int i = 0;

        while (n > 0) {
            if (n & 1) two.push_back(1 << i);
            n >>= 1;
            i++;
        }

        vector<long long> prefix(two.size());
        prefix[0] = two[0] % MOD;

        for (int i = 1; i < two.size(); i++) {
            prefix[i] = (prefix[i - 1] * two[i]) % MOD;
        }

        vector<int> ans(queries.size());
        i = 0;

        for (auto &it : queries) {
            int l = it[0];
            int r = it[1];

            if (l > 0) {
                long long inv = modPow(prefix[l - 1], MOD - 2);
                ans[i] = (int)((prefix[r] * inv) % MOD);
            } else {
                ans[i] = (int)prefix[r];
            }
            i++;
        }

        return ans;
    }
};
