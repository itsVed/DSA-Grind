class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = 0;
        int n = arr.size();

        stack<int> st;

        for(int i=0; i < n; i++){
            

            while(!st.empty() and arr[st.top()] > arr[i]){
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, (nse - pse - 1) * arr[ele]);
            }

            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, (nse - pse - 1) * arr[ele]);
        }

        return maxArea;
    }
};