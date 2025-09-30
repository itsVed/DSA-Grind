class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans = 1e18;
        long long leftsum = nums[0];
        int n = nums.size();
        long long rightsum = nums[n - 1];
        int peak = n - 1;

        for(int i=1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                peak = i - 1;
                break;
            }

            leftsum += nums[i];
        }

        if(peak == n - 1){
            return abs(leftsum - 2LL * nums[n - 1]);
        }

        for(int i=peak+1; i < n - 1; i++){
            if(nums[i] <= nums[i + 1]){
                return -1;
            }

            rightsum += nums[i];
        }

        ans = min(ans, abs(leftsum - rightsum));

        if(nums[peak] > nums[peak + 1] and leftsum > rightsum){
            ans = min(ans, abs(leftsum - rightsum - 2LL * nums[peak]));
        }


        return ans == 1e19 ? -1 : ans;

    }
};