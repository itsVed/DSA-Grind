class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int j, vector<int> &cuts){
        if(i > j) return 0;

        int maxi = 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        for(int ind = i; ind <= j; ind++){

            int cost = (cuts[j + 1] - cuts[i - 1]) + f(i,ind - 1, cuts) + f(ind + 1, j, cuts);
            maxi = min(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        dp.assign(cuts.size(), vector<int>(cuts.size(), -1));

        


        return f(1, cuts.size() - 2, cuts);
    }
};