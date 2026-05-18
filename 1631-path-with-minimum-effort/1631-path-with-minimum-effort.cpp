class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int eff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            int delRow[]={-1, 1, 0, 0};
            int delCol[]={0, 0, -1, 1};
            for(int i=0;i<4;i++){
                int r=row+delRow[i];
                int c=col+delCol[i];
                if(r>=0 && c>=0 && r<n && c<m){
                    int effort=abs(heights[row][col]-heights[r][c]);
                    int path= max(eff,effort);
                    if(path<dist[r][c]){
                        dist[r][c]=path;
                        pq.push({path,{r,c}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]<1e9) return dist[n-1][m-1];
        else return -1;

    }
};