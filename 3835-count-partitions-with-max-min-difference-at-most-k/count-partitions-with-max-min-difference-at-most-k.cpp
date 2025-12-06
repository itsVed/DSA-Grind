class Solution {
public:
    int MOD = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        vector<long long> pre(n + 1, 0);
        dp[0] = 1;
        pre[0] = 1;

        multiset<int> st;
        int j = 0;

        for(int i=0; i < n; i++){
            st.insert(nums[i]);

            while(j <= i and (*st.rbegin() - *st.begin()) > k){
                st.erase(st.find(nums[j]));
                j++;
            }

            if(j > 0){
                dp[i + 1] = (pre[i] - pre[j - 1] + MOD)%MOD;
            }
            else{
                dp[i + 1] = pre[i] % MOD;
            }

            pre[i + 1] = (pre[i] + dp[i + 1])% MOD;
        }

        return dp[n];
    }
};