class Solution {
public:
    void dfs(int r, int c,vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[r][c]=1;
        int m= grid.size();
        int n= grid[0].size();
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
                int row=r+delRow[i];
                int col=c+delCol[i];
                if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1 && !vis[row][col]){
                    dfs(row,col,vis,grid);            
                }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //start from the boundary and use visited grid
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        //make vis matrix
        vector<vector<int>> vis(m,vector<int>(n,0));
        //check columns 1 abd n 
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            if(grid[i][n-1]==1 && !vis[i][n-1]){
                dfs(i,n-1,vis,grid);
            }
        }
        //for rows 0 and n
        for(int i=0;i<n;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,vis,grid);
            }
            if(grid[m-1][i]==1 && !vis[m-1][i]){
                dfs(m-1,i,vis,grid);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] ==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};