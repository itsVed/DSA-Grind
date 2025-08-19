class Solution {
public:

    int f(vector<int> &nums) {
        stack<int> st;
        int maxArea = 0;
        int element, nse, pse;

        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                element = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, nums[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            element = st.top();
            st.pop();

            nse = nums.size();
            pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, nums[element] * (nse - pse - 1));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> vec(col, 0);
        int ans = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '1')
                    vec[j] += 1;
                else
                    vec[j] = 0;
            }

            ans = max(ans, f(vec));
        }

        return ans;
    }
};
