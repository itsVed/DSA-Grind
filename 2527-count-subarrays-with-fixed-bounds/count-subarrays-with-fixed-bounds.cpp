class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int maxpos = -1;
        int minpos = -1;
        int lastpos = -1;
        int n = nums.size();

        for(int i=0; i < n; i++){
            if(nums[i] == minK) minpos = i;
            
            if(nums[i] == maxK) maxpos = i;
            
            if(nums[i] < minK || nums[i] > maxK) lastpos = i;

            int smaller = min(minpos, maxpos);
            long long temp = smaller - lastpos;

            ans += temp < 0 ? 0 : temp;
        }

        return ans;
    }
};