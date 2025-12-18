class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> profit(n);

        long long initial = 0;

        for(int i=0; i < n; i++){
            profit[i] = (long long) strategy[i] * prices[i];
            initial += profit[i];
        }


        int i = 0;
        int j = 0;

        long long modified = 0;
        long long original = 0;
        long long profitgain = 0;

        while(j < n){
            
            original += profit[j];

            if(j - i + 1 > k / 2){
                modified += prices[j];
            }


            if(j - i + 1 > k){
                modified -= prices[i + k / 2];
                original -= profit[i];

                i++;
            }

            if(j - i + 1 == k){
                profitgain = max(profitgain, modified - original);
            }

            j++;
        }

        return initial + profitgain;
    }
};