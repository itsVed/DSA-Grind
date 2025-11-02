class Solution {
    public long maxProduct(int[] nums) {
        long ans = 1;
        int n = nums.length;

        for(int i=0; i < n; i++){
           if(nums[i] < 0) nums[i] = nums[i] * -1;
        }

        Arrays.sort(nums);
    
        ans *= nums[n - 1];
        ans *= nums[n - 2];
        ans *= 100000;

        return ans;
    }
}