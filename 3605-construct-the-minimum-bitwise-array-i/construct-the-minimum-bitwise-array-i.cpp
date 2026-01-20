class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        // n - 5
        // 0 1 2 3
        
        for(int i=0; i < n; i++){
            bool flag = true;
            for(int j=0; j <= nums[i]; j++){
                
                if((j | (j + 1)) == nums[i]){
                    ans[i] = j;
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans[i] = -1;
        }

        return ans;
    }
};