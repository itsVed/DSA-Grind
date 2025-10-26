class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int &i : nums) if(i < 0) i *= -1;

        sort(nums.begin(), nums.end());
        int i=0, j = n - 1;
        long long score = 0;
        bool flag = true;

        for(int k=0; k < n; k++){
            if(flag){
                ans[k] = nums[j];
                score += (ans[k] * ans[k]);
                j--;
            }
            else{
                ans[k] = nums[i];
                score -= (ans[k] * ans[k]);
                i++;
                
            }

            flag = !flag;
        }


        return score;
    }
};