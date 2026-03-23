class Solution {
public:
    bool isValid(int row, int col, char c,vector<vector<char>>& board){
        //row and col check
        for(int i=0;i<9;i++){
            if(board[row][i]==c||board[i][col]==c) return false;
        }
        //3x3 check
        for(int i=3*(row/3);i<3+3*(row/3);i++){
            for(int j=3*(col/3);j<3+3*(col/3);j++){
                if(board[i][j]==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=0;k<9;k++){
                        if(isValid(i,j,'1'+k,board)){
                            board[i][j]='1'+k;
                            if(solve(board)) return true;
                            board[i][j]='.';
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