class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        using PIII=pair<int,pair<int,int>>;
        priority_queue<PIII,vector<PIII>,greater<PIII>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            int currDist=it.first;
            int currRow=it.second.first;
            int currCol=it.second.second;
            pq.pop();
            if(currDist<dist[currRow][currCol]) continue;
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nextRow=currRow+delRow[i];
                int nextCol=currCol+delCol[i];
                if(nextRow>=0 && nextCol>=0 && nextRow<n && nextCol<m){
                    int effort=abs(heights[currRow][currCol]-heights[nextRow][nextCol]);
                    int path=max(effort,currDist);
                    if(path<dist[nextRow][nextCol]){
                        dist[nextRow][nextCol]=path;
                        pq.push({path,{nextRow,nextCol}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==INT_MAX)return -1;
        return dist[n-1][m-1];

    }
};