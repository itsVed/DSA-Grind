class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int[] freq = new int[101];
        int[] ans = new int[2];
        int j = 0;
        
        for(int i=0; i < nums.length; i++){
            if(freq[nums[i]] > 0){
                ans[j] = nums[i];
                j++;
            }

            freq[nums[i]]++;
        }

        return ans;
    }
}