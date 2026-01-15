class Solution {
public:
    // find y coordinate such that the both squares are equal

    bool check(vector<vector<int>>& squares, double mid, double total){
        double bottom = 0.00000;

        for(auto &sq :squares){
            double y = sq[1];
            double l = sq[2];

            double boty = y;
            double topy = y + l;

            if(mid >= topy){
                bottom += l * l;
            }
            else if(mid > boty){
                bottom += (mid - boty) * l;
            }
        }

        return bottom >= total / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double total = 0.00000;

        for(auto &sq: squares){
            double x = sq[0];
            double y = sq[1];
            double l = sq[2];

            total += l * l;

            low = min(y, low);
            high = max(y + l, high);
        }

        double res = 0.00000;

        while(high - low > 1e-5){
            double mid = low + (high - low) / 2;

            res = mid;

            if(check(squares, mid, total) == true){
                high = mid;
            }
            else{
                low = mid;
            }
        }

        return res;
    }
};