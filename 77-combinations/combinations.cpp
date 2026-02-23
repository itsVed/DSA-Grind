class Solution {
public:

    void solve(int idx, int n, int k, vector<int> &v, vector<vector<int>> &ans){

        if(v.size() == k){
            ans.push_back(v);
            return;
        }

        for(int i=idx+1; i <= n; i++){
            v.push_back(i);
            solve(i, n, k, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;

        solve(0, n, k, v, ans);

        return ans;
    }
};