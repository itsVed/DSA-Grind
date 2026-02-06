class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i=1, p = -1, q = -1, flag = -1;

        while(i < n and nums[i] > nums[i - 1]){
            i++;
        }

        p = i - 1;

        while(i < n and nums[i] < nums[i - 1]){
            i++;
        }

        q = i - 1;

        while(i < n and nums[i] > nums[i - 1]){
            i++;
        }

        flag = i - 1;

        if(p != 0 and q != p and flag == n - 1 and flag != q){
            return true;
        }

        return false;
    }
};