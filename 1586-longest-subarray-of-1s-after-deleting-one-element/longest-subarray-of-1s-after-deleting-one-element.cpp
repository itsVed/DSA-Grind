class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j = 0;
        int ans = 0;
        int zero = 0;
        int maxl = 0;

        while(j < nums.size()){

            if(nums[j] == 0) zero++;
            while(zero > 1){
                if(nums[i] == 0) zero--;
                i++;
            }

            maxl = max(maxl, j - i);

            j++;
        }

        return maxl;
    }
};