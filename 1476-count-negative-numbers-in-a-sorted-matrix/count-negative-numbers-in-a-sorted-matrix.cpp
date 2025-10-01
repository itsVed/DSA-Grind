class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int ans = 0;

        for(int i=0;i < row; i++){
            int low = 0, high = grid[0].size() - 1;
            int idx = grid[0].size();

            while(low <= high){
                int mid = low + (high - low)/2;
                
                if(grid[i][mid] < 0){
                    idx = mid;
                    high = mid - 1;
                } 
                else{
                    low = mid + 1;
                }
            }

            ans += (grid[0].size() - idx);
        }


        return ans;
    }
};