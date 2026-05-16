class Solution {
public:
    bool checkBFS(int start,vector<int> &color,vector<vector<int>>& graph){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int neighbour : graph[curr]){
                if(color[neighbour]==-1){
                    color[neighbour]=!color[curr];
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[curr]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        //connected components
        int n= graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!checkBFS(i,color,graph)) return false;
            }
        }
        return true;
    }
};