class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        if (n==1) return 1;
        queue<pair<int,int>> q;
        //use multisource bfs 8 directions using del row, del col
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            int row_node=q.front().first;
            int col_node=q.front().second;
            q.pop();
            //now neighbours:
            int delRow[] ={-1, 1, 0, 0, -1, -1, 1, 1};
            int delCol[] ={0, 0, -1, 1, -1, 1, -1, 1};
            for(int i=0;i<8;i++){
                int row_nei=row_node+delRow[i];
                int col_nei=col_node+delCol[i];
                if(row_nei>=0 &&col_nei>=0 && row_nei<n && col_nei<n && grid[row_nei][col_nei]==0 && 1+dist[row_node][col_node]<dist[row_nei][col_nei]){
                    dist[row_nei][col_nei]=1+dist[row_node][col_node];
                    q.push({row_nei,col_nei});
                }
            }
        }
        if(dist[n-1][n-1]<1e9) return dist[n-1][n-1];
        else return -1;
    }
};