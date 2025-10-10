class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        vector<int> dp(n + 1, 0);

        for(int i=n-1; i >= 0; i--){
            dp[i] = (i + k < n ? dp[i + k] : 0) + energy[i];
        }
        
        for(int i=0; i < n; i++){
            ans = max(dp[i], ans);
        }

        return ans;
    }
};