class Solution {
public:
    vector<int> delrow = {-1,-1,-1,0,0,1,1,1};
    vector<int> delcol = {-1,0,1,-1,1,-1,0,1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(grid[0][0] == 1 || grid[row-1][col-1] == 1) return -1;

        int ans = 1e9;

        queue<pair<int,int>> q;
        q.push({0, 0});

        grid[0][0] = 1;

        while(!q.empty()){
            auto[r, c] = q.front();
            q.pop();

            int dist = grid[r][c];

            if(r == row-1 && c == col-1) return dist;

            for(int k = 0; k < 8; k++){
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];

                if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && grid[nrow][ncol] == 0){
                   grid[nrow][ncol] = dist + 1;
                   q.push({nrow, ncol});
                }
            }
        }

        return -1;
    }
};
