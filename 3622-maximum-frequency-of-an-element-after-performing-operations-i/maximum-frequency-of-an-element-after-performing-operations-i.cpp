class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ele = *max_element(nums.begin(), nums.end());
        vector<int> freq(ele + 1);

        for(int num : nums){
            freq[num]++;
        }

        for(int i=1; i <= ele; i++){
            freq[i] += freq[i - 1];
        }

        int ans = 0;

        for(int i=0; i <= ele; i++){

            if(freq[i] == 0) continue;

            int left = max(0, i - k);
            int right = min(ele, i + k);

            int total = freq[right] - (left > 0 ? freq[left - 1] : 0);
            int element = freq[i] - (i > 0 ? freq[i - 1] : 0); 
            int con = total - element;

            ans = max(ans, element + min(con, numOperations));
        }

        return ans;
    }
};