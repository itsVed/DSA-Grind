class Solution {
public:
    typedef long long ll;

    ll countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size();
        ll i = 0;
        ll j = 0;
        ll ans = 0;

        map<int, int> mp;

        while(j < n){

            mp[nums[j]]++;

            while(i <= j){

                ll mini = mp.begin()->first;
                ll maxi = mp.rbegin()->first;

                ll cost = (maxi - mini) * (j - i + 1);

                if(cost > k){
                    
                    mp[nums[i]]--;

                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }

                    i++;
                }
                else{
                    break;
                }

            }
            
            ans += (j - i + 1);

            j++;
        }
            

        return ans;
    }
};