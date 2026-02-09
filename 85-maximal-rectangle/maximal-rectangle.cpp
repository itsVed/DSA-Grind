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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> height(col, 0);

        for(int i=0; i < row; i++){
            for(int j=0; j < col; j++){
                if(matrix[i][j] == '1'){
                    height[j] += 1;
                }
                else{
                    height[j] = 0;
                }
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};