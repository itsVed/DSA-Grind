class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int findidx(vector<vector<int>> &events, int end){
        int l = 0;
        int r = n - 1;
        int res = n;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(events[mid][0] > end){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return res;
    }

    int solve(vector<vector<int>> &events, int idx, int count){

        if(count == 2 || idx >= n){
            return 0;
        }

        if(dp[idx][count] != -1) return dp[idx][count];
         
        int next = findidx(events, events[idx][1]);
        int take = events[idx][2] + solve(events, next, count + 1);

        int skip = solve(events, idx + 1, count);

        return dp[idx][count] = max(take, skip);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        n = events.size();
        dp.resize(n + 1, vector<int>(3, -1));

        int count = 0;

        return solve(events, 0, count);
    }
};