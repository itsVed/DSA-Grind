class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        bool first = false;

        for(int i=0; i < n; i++){

            if(nums[i] == 0){
                len++;
            }
            else{
                if(!first){
                    first = true;
                    len = 0;
                    continue;
                }
               
                if(len < k){
                    return false;
                }

                len = 0;
            }
        }

        return true;
    }
};