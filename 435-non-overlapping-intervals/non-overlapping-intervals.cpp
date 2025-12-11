class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int ans = 0;
        int end = INT_MIN;

        for(auto &it : intervals){
            if(it[0] < end){
                ans++;
            }
            else{
                end = it[1];
            }
        }

        return ans;
    }
};
