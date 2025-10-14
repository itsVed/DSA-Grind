class Solution {
public:

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return true;
        if(n < 2*k) return false;

        auto check = [&](vector<int> &nums, int start, int k){
            for(int i=start; i < start + k - 1; i++){
                if(nums[i] >= nums[i + 1]){
                    return false;
                }
            }

            return true;
        };

        for(int i=0; i <= n - 2*k; i++){
            if(check(nums, i, k) and check(nums, i + k, k)) return true;
        }

        return false;
    }
};