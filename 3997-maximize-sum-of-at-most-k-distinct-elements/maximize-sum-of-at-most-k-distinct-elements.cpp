class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        set<int> st;

        for(int i=n-1; i >= 0 and k > 0; i--){
            if(!st.count(nums[i])){
                st.insert(nums[i]);
                ans.push_back(nums[i]);
                k--;
            }
        }

        return ans;
    }
};