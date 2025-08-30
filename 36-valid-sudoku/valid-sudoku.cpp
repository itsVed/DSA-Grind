class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // row wise
        for(int i=0; i < row; i++){
            set<char> st;
            for(int j=0; j < col; j++){
                if(board[i][j] == '.') continue;

                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }

        // column wise
        for(int i=0; i < col; i++){
            set<char> st;
            for(int j=0; j < row; j++){

                if(board[j][i] == '.') continue;

                if(st.count(board[j][i])) return false;
                st.insert(board[j][i]);
            }
        }

        // box wise
        for(int br = 0; br < 9; br += 3){ 
            for(int bc = 0; bc < 9; bc += 3) { 
                set<char> st; 
                for(int i = 0; i < 3; i++) { 
                    for(int j = 0; j < 3; j++) { 
                        char curr = board[br + i][bc + j]; 
                        if(curr == '.') continue; 
                        
                        if(st.count(curr)) return false; 
                        st.insert(curr); 
                    } 
                } 
            } 
        }

        return true;
    }
};