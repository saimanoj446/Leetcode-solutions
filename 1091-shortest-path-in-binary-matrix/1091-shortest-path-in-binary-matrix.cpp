class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n= grid.size();
        int m=grid[0].size();
        //edge cases: if initialized with 1 and only one cell
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        if (n == 1 && m == 1) return 1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int delrow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        q.push({1,{0,0}});
        dist[0][0] = 1;
        while(!q.empty()){
            int r=q.front().second.first;//row
            int c=q.front().second.second;//column
            int d=q.front().first;//dist
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && d+1<dist[nrow][ncol] && grid[nrow][ncol]==0){
                    dist[nrow][ncol]=1+d;
                    if(nrow==n-1 && ncol==m-1){
                        return 1+d;
                    }
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};