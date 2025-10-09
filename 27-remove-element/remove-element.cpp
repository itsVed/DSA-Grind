class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        while(i <= j){
            if(nums[i] != val){
                i++;
            }
            else if(nums[j] == val){
                j--;
            }
            else{
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        return i;
    }
};