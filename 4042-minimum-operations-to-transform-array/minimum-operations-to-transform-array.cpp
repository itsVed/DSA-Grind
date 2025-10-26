class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int best = INT_MAX;

        for(int i=0; i < nums1.size(); i++){
            ans += abs(nums2[i] - nums1[i]);

            if(max(nums1[i], nums2[i]) >= nums2.back() and min(nums1[i], nums2[i]) <= nums2.back()){
                best = 1;
            }

            best = min(best, 1 + min(abs(nums1[i] - nums2.back()), abs(nums2[i] - nums2.back())));
        }
        
        return ans + best;

    }
};