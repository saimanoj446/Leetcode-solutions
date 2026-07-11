class Solution {
public:
    bool dfs(int n,int prev_color,vector<int> &color,vector<vector<int>>& graph){
        color[n]=prev_color;
        for(auto node:graph[n]){
            if(color[node]==-1){
                if(dfs(node,1-prev_color,color,graph)==false) return false;
            }
            else if(prev_color==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};