class Solution {
public:
    typedef int ll;

    int deleteAndEarn(vector<int>& nums) {
        map<ll, ll> mp;
        unordered_map<ll, ll> dp;

        for(int a: nums){
            mp[a]++;
        }

        ll ans = 0, prev, back = 0;

        for(auto [el, freq] : mp){
            auto backit = mp.lower_bound(el - 1);

            if(backit != mp.begin()) back = (*(--backit)).first;
        
            dp[el] = max(dp[prev], freq * el + dp[back]);
            ans = max(ans, dp[el]);
            prev = el;
        }

        return ans;
    }
};