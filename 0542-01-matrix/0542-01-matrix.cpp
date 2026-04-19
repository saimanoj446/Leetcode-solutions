class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        //now actual bfs
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int minDist=q.front().second;
            ans[x][y] = minDist;
            q.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int  i=0;i<4;i++){
                int r=x+delRow[i];
                int c=y+delCol[i];
                if(r>=0 && c>=0 && r<n && c<m && !vis[r][c]){
                    q.push({{r,c},minDist+1});
                    vis[r][c]=1;
                }
            }
        }
        return ans;
    }
};