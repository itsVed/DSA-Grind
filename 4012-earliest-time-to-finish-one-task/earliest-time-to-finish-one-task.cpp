class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;

        for(vector<int> v : tasks){
            int start = v[0];
            int end = v[1];

            ans = min(ans, start + end);
        }

        return ans;
    }
};