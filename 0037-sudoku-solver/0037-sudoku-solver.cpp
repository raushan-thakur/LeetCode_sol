class Solution {
public:
    bool isPossible(int row, int col, char ch, vector<vector<char>>& b){
        for(int i=0; i< 9; i++){
            if(b[row][i] == ch) return false;
            if(b[i][col] == ch) return false;
            if(b[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                if(board[i][j] == '.'){
                    for(int ch = '1'; ch<='9'; ch++){
                        if(isPossible(i, j, ch, board)){
                            board[i][j] = ch;
                            if(solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};