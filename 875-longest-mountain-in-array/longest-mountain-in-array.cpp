class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> inc(n, 0);
        vector<int> dec(n, 0);

        for(int i=0; i< n; i++){
            if(i > 0 and arr[i] > arr[i - 1]){
                inc[i] = inc[i  - 1] + 1;
            }
        }

        for(int i=n-1; i >= 0; i--){
            if(i < n - 1 and arr[i] > arr[i + 1]){
                dec[i] = dec[i + 1] + 1;
            }
        }

        int ans = 0;

        for(int i=0; i < n - 1; i++){
            if(inc[i] > 0 and dec[i] > 0){
                ans = max(ans, inc[i] + dec[i] + 1);
            }
        }

        return ans;
    }
};