class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();
        stack<int> st;

        for(int i=0; i < n; i++){


            while(!st.empty() and st.top() > nums[i]){
                st.pop();
            }
            
            if(nums[i] == 0) continue;

            if(st.empty() || st.top() < nums[i]){
                ops++;
                st.push(nums[i]);
            }
        }
        
        return ops;
    }
};