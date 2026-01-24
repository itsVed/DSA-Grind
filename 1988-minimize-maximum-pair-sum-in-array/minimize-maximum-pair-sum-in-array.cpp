class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;

        int ans = INT_MIN;
        vector<int> a;

        while(i < j){
            a.push_back(nums[i] + nums[j]);
            i++;
            j--;
        }

        for(auto it : a){
            ans = max(ans, it);
        }

        return ans;
    }
};