class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int row = points.size();
        int col = points.size();
        int count = 0;

        vector<int> visited(row, false);

        for(int i=0; i < row; i++){
            for(int j=i + 1; j < row; j++){
                visited[i] = true;
                visited[j] = true;

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if ((x1 <= x2 && y1 >= y2) || (x2 <= x1 && y2 >= y1)){
                    bool valid = true;

                    int left   = min(x1, x2);
                    int right  = max(x1, x2);
                    int bottom = min(y1, y2);
                    int top    = max(y1, y2);

                    for (int k = 0; k < row; k++) {
                        if (!visited[k]) {
                            int x = points[k][0];
                            int y = points[k][1];

                            if (left <= x && x <= right && bottom <= y && y <= top) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) count++;
                }

                visited[i] = false;
                visited[j] = false;
            }
        }

        return count;
    }
};