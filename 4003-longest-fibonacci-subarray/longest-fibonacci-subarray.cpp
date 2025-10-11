class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int count = 2;

        for(int i=2; i < n; i++){
            if(nums[i] == nums[i - 1] + nums[i - 2]){
                count++;
                ans = max(ans, count);
            }else{
                count = 2;
            }
        }

        ans = max(ans, count);
        return ans;
    }
};