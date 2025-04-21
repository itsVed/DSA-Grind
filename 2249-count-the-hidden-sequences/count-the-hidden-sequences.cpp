class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int minV = 0;
        int maxV = 0;

        int a = 0;

        for(int i=0; i < d.size(); i++){
            a += d[i];

            maxV = max(maxV, a);
            minV = min(minV, a);

            // alpha should be between maxV + alpha <= upper and minV + alpha >= lower
            // lower - minV <= alpha <= upper - maxV
            
            if(((upper - maxV) - (lower - minV) + 1 < 0)) return 0;
        }

        return (upper - maxV) - (lower - minV) + 1;
    }
};