class Solution {
public:
    int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mp;

        for(auto v: points){
            int y = v[1];
            mp[y]++;
        }

        for(auto &it : mp){
            long long val = it.second;
            it.second = (val* (val - 1))/2 % MOD;
        }

        long long ans = 0;
        long long sum = 0;

        for(auto &it : mp){
            ans = (ans + (it.second * sum) % MOD) % MOD;
            sum = (sum + it.second) % MOD;
        }

        return (int) ans;
    }
};