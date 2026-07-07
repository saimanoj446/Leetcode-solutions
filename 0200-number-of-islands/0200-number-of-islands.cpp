class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[i][j]=1;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int r=i+delRow[k];
            int c=j+delCol[k];
            if(r>=0&&c>=0&&r<grid.size()&&c<grid[0].size()&&!vis[r][c]&&grid[r][c]=='1'){
                dfs(r,c,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};