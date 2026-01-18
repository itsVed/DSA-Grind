class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> rowsum(row, vector<int>(col, 0));

        for(int i=0; i < row; i++){
            rowsum[i][0] = grid[i][0];

            for(int j=1; j < col; j++){
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }

        vector<vector<int>> colsum(row, vector<int>(col, 0));

         for(int j=0; j < col; j++){
            colsum[0][j] = grid[0][j];

            for(int i=1; i < row; i++){
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        for(int side = min(row, col); side >= 2; side--){

            for(int i=0; i + side - 1 < row; i++){
                for(int j=0; j + side - 1 < col; j++){
                    
                    int target = rowsum[i][j + side - 1] - (j > 0 ? rowsum[i][j - 1] : 0);

                    bool allsame = true;

                    // row check
                    for(int r = i + 1; r < i + side; r++){

                        int rsum = rowsum[r][j + side - 1] - (j > 0 ? rowsum[r][j - 1] : 0);

                        if(rsum != target){
                            allsame = false;
                            break;
                        }
                    }

                    if(!allsame){
                        continue;
                    }

                    // col check

                    for(int c = j; c < j + side; c++){

                        int csum = colsum[i + side - 1][c] - (i > 0 ? colsum[i - 1][c] : 0);

                        if(csum != target){
                            allsame = false;
                            break;
                        }
                    }

                    if(!allsame){
                        continue;
                    }


                    // diagonal

                    int dia = 0;
                    int anti = 0;

                    for(int k=0; k < side; k++){
                        dia += grid[i + k][j + k];
                        anti += grid[i + k][j + side - 1 - k];
                    }

                    if(dia == target and anti == target){
                        return side;
                    }

                }
            }
        }

        return 1;
    }
};