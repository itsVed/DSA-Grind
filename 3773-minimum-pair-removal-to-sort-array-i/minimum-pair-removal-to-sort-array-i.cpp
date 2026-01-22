class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (true) {
            bool nonDecreasing = true;

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    nonDecreasing = false;
                    break;
                }
            }

            if (nonDecreasing) break;

            int minSum = INT_MAX;
            int idx = 0;

            for (int i = 0; i < nums.size() - 1; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }

        return operations;
    }
};
