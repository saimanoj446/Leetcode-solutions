class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
    for (int r = 0; r < row; r++) {
        if (board[r][col] == 'Q') return false;
    }
    int r = row;
    int c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--; // Move up
        c--; // Move left
    }
    r = row;
    c = col;
    while (r >= 0 && c < n) {
        if (board[r][c] == 'Q') return false;
        r--; // Move up
        c++; // Move right
    }
    return true;
}
    void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        solve(0,board,ans,n);
        return ans;
    }
};