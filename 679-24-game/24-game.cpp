class Solution {
public:

    bool f(vector<double> &nums) {
        if (nums.size() == 1) return abs(nums[0] - 24) < 1e-6;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < nums.size(); ++k)
                    if (k != i && k != j) next.push_back(nums[k]);
                for (double x : {
                    nums[i] + nums[j],
                    nums[i] - nums[j],
                    nums[j] - nums[i],
                    nums[i] * nums[j],
                    nums[j] != 0 ? nums[i] / nums[j] : 1e9,
                    nums[i] != 0 ? nums[j] / nums[i] : 1e9
                }) {
                    next.push_back(x);
                    if (f(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return f(nums);
    }
};