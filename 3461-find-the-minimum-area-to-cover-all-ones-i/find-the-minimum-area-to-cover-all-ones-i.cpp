class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = INT_MAX, maxRow = INT_MIN;
        int minCol = INT_MAX, maxCol = INT_MIN;
        
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};