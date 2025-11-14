class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for(vector<int> q : queries){
            int x1 = q[0];
            int y1 = q[1];
            int x2 = q[2];
            int y2 = q[3];

            for(int i=x1; i <= x2; i++){
                for(int j=y1; j <= y2; j++){
                    mat[i][j] += 1;
                }
            }
        }
        
        return mat;
    }
};