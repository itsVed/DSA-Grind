class Solution {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i < n;i++){
            auto j = lower_bound(ans.begin(), ans.end(), nums[i]);

            if(j == ans.end()) ans.push_back(nums[i]);
            else *j = nums[i];
        }

        return ans.size();
    }
};