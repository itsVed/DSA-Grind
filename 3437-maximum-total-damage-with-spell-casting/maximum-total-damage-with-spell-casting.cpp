class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        map<ll, ll> mp;
        unordered_map<ll, ll> dp;

        for(int a: power){
            mp[a]++;
        }

        ll ans = 0, prev, back = 0, n = power.size();

        for(auto [el, freq] : mp){
            auto backit = mp.lower_bound(el - 2);

            if(backit != mp.begin()) back = (*(--backit)).first;
        
            dp[el] = max(dp[prev], freq * el + dp[back]);
            ans = max(ans, dp[el]);
            prev = el;
        }

        return ans;
    }
};