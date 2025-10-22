class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 1;
        map<int,int> diff; // to store the element which are possibily the target and the nums element(the range of nums[i] - k to nums[i] + k)
        unordered_map<int, int> freq; // to store the frequency of element in nums
        int ele = *max_element(nums.begin(), nums.end()) + k;
        
        for(int num : nums){

            freq[num]++;

            int l = max(0, num - k); // taking the range of num - k
            int r = min(ele, num + k); // taking the range of num + k

            diff[l]++; // maintainig the difference map
            diff[r + 1]--;

            diff[num] += 0;
        }

        int cumsum = 0;
        for(auto it = diff.begin(); it != diff.end(); it++){
            
            int target = it->first;
            it->second += cumsum;

            int total = freq[target];
            int element = it->second - total;
    
            ans = max(ans, total + min(element, numOperations));

            cumsum = it->second;
        }

        return ans;

    }
};