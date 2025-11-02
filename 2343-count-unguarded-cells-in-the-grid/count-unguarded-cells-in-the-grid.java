class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int ans = 0;
        int[][] grid = new int[m][n];

        for(int[] pos : guards){
            grid[pos[0]][pos[1]] = 1;
        }

        for(int[] pos : walls){
            grid[pos[0]][pos[1]] = 2;
        }

        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                if(grid[i][j] == 1){
                    
                    // up
                    for (int k = i - 1; k >= 0; k--) {
                        if (grid[k][j] == 2 || grid[k][j] == 1) break;
                        grid[k][j] = 3;
                    }

                    // right
                    for (int k = j + 1; k < n; k++) {
                        if (grid[i][k] == 2 || grid[i][k] == 1) break;
                        grid[i][k] = 3;
                    }

                    // down
                    for (int k = i + 1; k < m; k++) {
                        if (grid[k][j] == 2 || grid[k][j] == 1) break;
                        grid[k][j] = 3;
                    }

                    // left
                    for (int k = j - 1; k >= 0; k--) {
                        if (grid[i][k] == 2 || grid[i][k] == 1) break;
                        grid[i][k] = 3;
                    }


                }
            }
        }

        for(int i=0; i < m; i++){
            for(int j=0; j < n; j++){
                if(grid[i][j] == 0){
                    ans++;
                }
            }
        }

        return ans;
    }
}