class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        long long prod = 1;

        if(k <= 1) return 0;

        while(j < n){
            prod = (long long) prod * nums[j];

            while( prod >= k){
                prod /= nums[i];
                i++;
            }

            ans += (j - i + 1);

            j++;
        }

        return ans;
    }
};