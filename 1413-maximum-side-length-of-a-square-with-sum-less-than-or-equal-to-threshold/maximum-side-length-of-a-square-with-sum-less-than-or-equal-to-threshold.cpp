class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> prefix(row, vector<int>(col, 0));

        for(int i=0; i < row; i++){
            for(int j=0; j < col; j++){
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) 
                                + (j > 0 ? prefix[i][j - 1] : 0)
                                - ((i > 0 and j > 0) ? prefix[i - 1][j - 1] : 0)
                                + mat[i][j];
            }
        }

        int max_side = 0;

        auto sumSquare = [&](int i, int j, int r, int c){
            int sum = prefix[r][c];

            if(i > 0){
                sum -= prefix[i - 1][c];
            }

            if(j > 0){
                sum -= prefix[r][j - 1];
            }

            if(i > 0 and j > 0){
                sum += prefix[i - 1][j - 1];
            }

            return sum;
        };

        for(int i=0; i < row; i++){
            for(int j=0; j < col; j++){

                for(int k=0; k < min(row - i, col - j); k++){

                    int r = i + k;
                    int c = j + k;
                    
                    int sum = sumSquare(i, j, r, c);

                    if(sum <= threshold){
                        max_side = max(max_side, k + 1);
                    }
                    else{
                        break;
                    }

                }
            }
        }

        return max_side;
    }
};