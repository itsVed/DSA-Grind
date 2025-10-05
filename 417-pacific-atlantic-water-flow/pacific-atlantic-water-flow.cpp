class Solution {
public:

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    void dfs(int i, int j, int row, int col, vector<vector<int>> &heights, vector<vector<bool>> &vis){

        vis[i][j] = true;

        for(int k=0; k < 4; k++){
            int newi = i + delrow[k];
            int newj = j + delcol[k];

            if(newi >= 0 and newi < row and newj >= 0 and newj < col and !vis[newi][newj] and heights[newi][newj] >= heights[i][j]){
                dfs(newi, newj, row, col, heights, vis);
            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));

        // top row
        for(int j=0; j < col; j++){
            dfs(0, j, row, col, heights, pacific);
        }

        // left column
        for(int i=0; i < row; i++){
            dfs(i, 0, row, col, heights, pacific);
        }

        // right column
        for(int i=0; i<row; i++){
            dfs(i, col - 1, row, col, heights, atlantic);
        }

        // bottom down
        for(int j=0;j < col; j++){
            dfs(row - 1, j, row, col, heights, atlantic);
        }

        vector<vector<int>> ans;
        for(int i=0; i<row; i++){
            for(int j=0; j <col; j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};