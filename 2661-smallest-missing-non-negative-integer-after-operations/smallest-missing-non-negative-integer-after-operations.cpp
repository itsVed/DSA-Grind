class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int v) {
        vector<int> vec(v, 0);
        int n = nums.size();

        for(int i: nums){
            vec[((i % v) + v) % v]++;
        }

        int j = 0;
        while(true){
            int x = j % v;

            if(vec[x] == 0){
                return j;
            }

            vec[x]--;

            j++;
        }

        return -1;
    }
};