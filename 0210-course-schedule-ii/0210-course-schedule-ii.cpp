class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj, vector<int> &vis,vector<int> &pathvis,vector<int> &ans){
        vis[node]=1;
        pathvis[node]=1;
        for(int neighbour: adj[node]){
            if(!vis[neighbour]&&!pathvis[neighbour]){
                if(dfs(neighbour,adj,vis,pathvis,ans)==true){
                    return true;
                }
            }
            else if(pathvis[neighbour]){
                return true;
            }
        }
        pathvis[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        //converted into adj list
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,ans)==true){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};