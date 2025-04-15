class Solution {
public:
    long long gethour(int mid, vector<int> &piles){
        long long total = 0;

        for(auto it: piles){
            total += ((long long)it + mid - 1) / mid;
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long hour = gethour(mid, piles);

            if(hour <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
