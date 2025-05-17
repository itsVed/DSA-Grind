class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n - 1;
        // Dutch Nation Algorithm

        while(j <= k){
            if(nums[j] == 0){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }
            else if(nums[j] == 1){
                j++;
            }
        }
    }
};