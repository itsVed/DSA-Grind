class Solution {
public:
    // function to checking the possible k size subarray which sum is n
    vector<vector<int>> solve(int idx, int sum, int k, vector<int> &ds, vector<vector<int>> &ans){
        if(sum == 0 and k == 0){ // only inserting when we have k size array whose sum is equal to n
            ans.push_back(ds); // pushing the ds into our ans
            return ans;
        }

        if(k < 0) return {}; // for checking not taking greater then k elements into our array

        for(int i=idx; i <= 9; i++){ // loop from 1 to 9
            
            if(i > sum) break;

            ds.push_back(i); // taking the i
            solve(i + 1, sum - i, k - 1, ds, ans);
            ds.pop_back(); // skipping the i for the next term
        }

        return ans; // returning the ans
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; // for storing the valid combinations
        vector<int> ds;

        return solve(1, n, k, ds, ans);
    }
};