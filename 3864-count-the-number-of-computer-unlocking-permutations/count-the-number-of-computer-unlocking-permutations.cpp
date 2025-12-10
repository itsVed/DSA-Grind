class Solution {
public:
    int MOD = 1e9 + 7;
    int countPermutations(vector<int>& com) {
        long long ans = 1;
        int n = com.size();

        for(int i=1; i < n; i++){
            if(com[i] <= com[0]){
                return 0;
            }
        }

        for(int i=1; i < n; i++){
            ans = (ans * i) % MOD;
        }

        return (int)ans;
    }
};