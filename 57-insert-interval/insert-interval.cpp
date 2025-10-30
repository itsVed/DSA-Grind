class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& iv, vector<int>& ni) {
        vector<vector<int>> ans;
        iv.push_back({ni[0], ni[1]});
        int n = iv.size();
        sort(iv.begin(), iv.end());

        int start = iv[0][0];
        int end = iv[0][1];

        for(int i=1; i < n; i++){
            if(iv[i][0] > end){
                ans.push_back({start, end});
                start = iv[i][0];
                end = iv[i][1];
            }
            else{
                end = max(end, iv[i][1]);
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};