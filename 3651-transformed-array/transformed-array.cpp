class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int i = 0;

        while(i < n){
            if(nums[i] > 0){
                int idx = (i + nums[i]) % n;
                ans[i] = nums[idx];
            }
            else if(nums[i] < 0){
                int idx = ((i + nums[i]) % n + n) % n;
                ans[i] = nums[idx];
            }
            else{
                ans[i] = nums[i];
            }
            i++;
        }

        return ans;
    }
};