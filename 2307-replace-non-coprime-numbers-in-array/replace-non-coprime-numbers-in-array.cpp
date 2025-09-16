class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(int i=0; i < n; i++){
            
            while(!st.empty() and gcd(nums[i], st.top()) > 1){
                nums[i] = lcm(nums[i], st.top());
                st.pop();
            }

            st.push(nums[i]);
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};