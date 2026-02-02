class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        for(int i=0; i < 1; i++){
            for(int j=i+1; j < n; j++){
                for(int k=j+1; k < n; k++){
                    ans = min(ans, nums[i] + nums[j] + nums[k]);
                }
            }
        }

        return ans;
    }
};