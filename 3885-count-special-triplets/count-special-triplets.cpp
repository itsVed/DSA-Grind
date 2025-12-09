class Solution {
public:
    int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long, long long> right;
        unordered_map<long long, long long> left;

        for(int n : nums){
            right[n]++;
        }

        long long ans = 0;

        for(int j=0; j < nums.size(); j++){
            long long mid = nums[j];
            right[mid]--;

            long long need = mid * 2;

            long long leftcount = left[need];
            long long rightcount = right[need];

            ans = (ans + leftcount * rightcount) % MOD;

            left[mid]++;
        }

        return ans;
    }
};