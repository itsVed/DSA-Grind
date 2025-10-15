class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n, 0);
        inc[n - 1]  = 1;

        for(int i=n-2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                inc[i] = inc[i + 1] + 1;
            }
            else{
                inc[i] = 1;
            }
        }

        auto ispossible = [&](int k) {
            for (int i = 0; i + k < n; ++i) {
                if (inc[i] >= k && inc[i + k] >= k)
                    return true;
            }
            return false;
        };


        int low = 1, high = n/2;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(ispossible(mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};