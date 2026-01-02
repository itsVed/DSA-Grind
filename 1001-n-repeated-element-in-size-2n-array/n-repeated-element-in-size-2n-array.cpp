class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;

        for(int i=1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i]){
                count++;
            }
            else{
                if(count == nums.size()/2){
                    return nums[i - 1];
                }

                count = 1;
            }
        }

        if(count == nums.size()/2){
            return nums[nums.size() - 1];
        }

        return -1;
    }
};