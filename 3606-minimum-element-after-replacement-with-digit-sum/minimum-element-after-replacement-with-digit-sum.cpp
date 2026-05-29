class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for(auto i : nums){
            int sum = 0;

            while(i > 0){
                sum += i % 10;
                i /= 10;
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};