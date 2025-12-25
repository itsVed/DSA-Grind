class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(), h.end(), greater<>());

        long long sum = 0;
        
        for(int i = 0; i < k; i++){
            long long val = h[i] - i;
            
            if(val <= 0) break;
            sum += val;
        }

        return sum;
    }
};
