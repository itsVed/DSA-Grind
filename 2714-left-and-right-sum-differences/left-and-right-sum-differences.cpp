class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int r = 0;

        for(int a : nums){
            r += a;
        }
        int n = nums.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        right[0] = r - nums[0];
        vector<int> ans(n);
        ans[0] = abs(left[0] - right[0]);

        for(int i=1; i < n; i++){
            left[i] = left[i - 1] + nums[i - 1];
            right[i] = right[i - 1] - nums[i];

            ans[i] = abs(right[i] - left[i]);
        }

        return ans;
    }
};