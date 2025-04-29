class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0;
        int n = nums.size();
        int i = 0, j = 0;
        
        int maxE = *max_element(nums.begin(), nums.end());
        int freq = 0;

        while (j < n) {
            if (nums[j] == maxE) {
                freq++;
            }

            while (freq >= k) {
                count += (n - j);
                if (nums[i] == maxE) {
                    freq--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};
