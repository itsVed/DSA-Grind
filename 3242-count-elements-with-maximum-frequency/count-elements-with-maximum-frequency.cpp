class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int freq = INT_MIN;

        for(int a: nums){
            mp[a]++;
            freq = max(freq, mp[a]);
        }

        int ans = 0;

        for(auto i: mp){
            if(i.second == freq){
                ans += i.second;
            }
        }


        return ans;
    }
};