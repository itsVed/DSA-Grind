class Solution {
public:
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int MOD = 1e9 + 7;
        
        int n = nums.size();

        for(int i=0; i < q.size(); i++){
            
            int li = q[i][0];
            int ri = q[i][1];
            int ki = q[i][2];
            int vi = q[i][3];

            for(int idx = li; idx <= ri; idx += ki){
                nums[idx] = (int)(((long long)nums[idx] * vi) % MOD);
            }
        }
        

        int ans = nums[0];

        for(int i=1; i < n; i++){
            ans ^= nums[i];
        }

        return ans;
    }
};