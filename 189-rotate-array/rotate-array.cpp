class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<int> ans(n);

        if(k >= n){
            int idx = k - n;

            for(int i=0; i < n; i++){
                ans[(i + idx)% n] = nums[i];
            }
        }
        else{

            int idx = n - k;
            int a = 0;

            for(int i=idx; i < n; i++){
                ans[a++] = nums[i];
            }

            for(int i=0; i < n - k; i++){
                ans[a++] = nums[i];
            }

        }
        
        nums = ans;
    }
};