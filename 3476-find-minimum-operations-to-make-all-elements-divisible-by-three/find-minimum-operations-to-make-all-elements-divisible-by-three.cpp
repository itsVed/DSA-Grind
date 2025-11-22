class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for(int num : nums){
            if(num % 3 != 0){ // as we know if any number is not divisible by 3 it gives either 1 or 2 as remainder and in both 
                ans++;        // the cases we just have to add or subtract 1 from that element so we just do one operation in any
            }                 // num which is not divisible by 3 just one time so increase our answer by 1
        }

        return ans;
    }
};