class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        pq.push({grid[0][0], {0,0}});

        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};

        while(!pq.empty()) {
            auto [currMax, pos] = pq.top(); pq.pop();
            int i = pos.first, j = pos.second;
            if(i == n-1 && j == n-1) return currMax;
            if(vis[i][j]) continue;
            vis[i][j] = true;

            for(int k=0;k<4;k++){
                int ni = i + delRow[k];
                int nj = j + delCol[k];
                
                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj]){
                    pq.push({max(currMax, grid[ni][nj]), {ni,nj}});
                }
            }
        }

        return -1;
    }
};
