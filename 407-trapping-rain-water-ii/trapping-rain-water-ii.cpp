class Solution {
public:

    typedef pair<int, pair<int,int>> PP;

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        int col = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        vector<vector<bool>> visited(row, vector<bool> (col, false));

        for(int i=0; i < row; i++){
            for(auto j : {0, col - 1}){
                pq.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }

        for(int i=0; i < col; i++){
            for(auto j : {0, row - 1}){
                pq.push({heightMap[j][i], {j, i}});
                visited[j][i] = true;
            }
        }

        int water = 0;
        while(!pq.empty()){
            
            PP p = pq.top();
            pq.pop();

            int height = p.first;
            int i_ = p.second.first;
            int j_ = p.second.second;

            for(int k=0; k < 4; k++){
                int new_i = i_ + delrow[k];
                int new_j = j_ + delcol[k];

                if(new_i >= 0 and new_i < row and new_j >= 0 and new_j < col and !visited[new_i][new_j]){
                    water += max(height - heightMap[new_i][new_j], 0);

                    pq.push({max(height, heightMap[new_i][new_j]), {new_i, new_j}});

                    visited[new_i][new_j] = true;
                }
            }
        }

        return water;

    }
};