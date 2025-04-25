class Solution {
public:
    // LC - 974 for reference
    // prefix sum for the counting the no which give modulo equal to k
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, long long> mp;
        long long sum = 0;

        mp[0] = 1;

        for(int i=0; i < n; i++){
            if(nums[i] % m == k){
                sum += 1;
            }

            int r1 = sum % m;
            int r2 = (r1 - k + m) % m;

            ans += mp[r2];
            mp[r1]++;
        }

        return ans;
    }
};