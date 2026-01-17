class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long large = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // top-right
                int fsx = topRight[i][0];
                int fsy = topRight[i][1];

                int ssx = topRight[j][0];
                int ssy = topRight[j][1];

                // bottom-left
                int bfsx = bottomLeft[i][0];
                int bfsy = bottomLeft[i][1];

                int bssx = bottomLeft[j][0];
                int bssy = bottomLeft[j][1];

                int width = min(fsx, ssx) - max(bfsx, bssx);
                int height = min(fsy, ssy) - max(bfsy, bssy);

                if(width > 0 && height > 0){
                    long long side = min(width, height);
                    large = max(large, side * side);
                }
            }
        }

        return large;
    }
};
