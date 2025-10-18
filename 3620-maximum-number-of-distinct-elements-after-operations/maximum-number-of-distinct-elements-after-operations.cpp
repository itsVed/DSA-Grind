class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int prev = INT_MIN;
        int count = 0;
        sort(nums.begin(), nums.end());
        
        for(int num : nums){
            int lower = num - k;
            int upper = num + k;

            if(prev < lower){
                prev = lower;
                count++;
            }
            else if(prev < upper){
                prev++;
                count++;
            }
        }
        
        return count;
    }
};