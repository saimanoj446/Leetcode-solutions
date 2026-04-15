class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();//rows
        int n=grid[0].size();//cols
        int freshCount=0;
        queue<pair<pair<int,int>,int>> q;//<row,col>,time
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }
        int maxTime=0;
        //BFS:
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int t= q.front().second;
            q.pop();
            //check neighbours
            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) {
                int nrow = r + dRow[i];
                int ncol = c + dCol[i];
                if(nrow>=0&&ncol>=0&&nrow<m&&ncol<n&&grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                    maxTime=max(maxTime,t+1);
                    freshCount--;
                }
            }
        }
        return (freshCount==0)?maxTime:-1;
    }
};