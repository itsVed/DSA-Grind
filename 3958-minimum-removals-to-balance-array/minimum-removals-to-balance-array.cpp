class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, maxlen = 0;

        for(int j=0; j < n; j++){
            while(i <= j and (long long)nums[j] > (long long)nums[i] * k){
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
        }

        return n - maxlen;
    }
};