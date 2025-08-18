class Solution {
public:
    int n;
    vector<int> dp;
    
    int f(int i, int k, vector<int> &arr){
        if(i == n) return 0;

        int maxSum = -1e9;
        int sum = 0;
        int maxi = -1e9;

        if(dp[i] != -1) return dp[i];

        for(int j=i; j < min(n, i + k); j++){
            maxi = max(maxi, arr[j]);
            sum = maxi * (j - i + 1) + f(j + 1, k, arr);
            maxSum = max(sum, maxSum);
        }

        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n, -1);

        return f(0, k, arr);
    }
};