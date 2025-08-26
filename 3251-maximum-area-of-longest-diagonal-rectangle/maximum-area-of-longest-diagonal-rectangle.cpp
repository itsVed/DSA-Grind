class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long diagonal = 0; 
        int area = 0;

        for (auto &dim : dimensions) {
            long long d = 1LL * dim[0] * dim[0] + 1LL * dim[1] * dim[1];
            int currArea = dim[0] * dim[1];

            if (d > diagonal) { 
                diagonal = d;
                area = currArea;
            } 
            else if (d == diagonal) {
                area = max(area, currArea);
            }
        }

        return area;
    }
};