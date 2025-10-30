class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = 0;

        int prev = 0;
        int curr = 0;

        for(int i=0; i < n; i++){
            curr = target[i];

            if(curr > prev){
                ans += (curr - prev);
            }

            prev = curr;
        }
        

        return ans;
    }
};