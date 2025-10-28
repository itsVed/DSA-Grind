class Solution {
public:
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    bool dfs(int i, int j, int row, int col, vector<vector<char>>& board, string &word, int idx, vector<vector<bool>>& vis) {
        if (idx == word.size() - 1 && board[i][j] == word[idx]) return true;
        if (board[i][j] != word[idx]) return false;

        vis[i][j] = true;

        for (int dir = 0; dir < 4; dir++) {
            int ni = i + delrow[dir];
            int nj = j + delcol[dir];

            if (ni >= 0 && ni < row && nj >= 0 && nj < col && !vis[ni][nj]) {
                if (dfs(ni, nj, row, col, board, word, idx + 1, vis))
                    return true;
            }
        }

        vis[i][j] = false;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> vis(row, vector<bool>(col, false));
                    if (dfs(i, j, row, col, board, word, 0, vis))
                        return true;
                }
            }
        }

        return false;
    }
};
