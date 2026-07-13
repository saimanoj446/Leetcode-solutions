class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //uses dijkistra algo
        //convert edges to adj
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto edge:times){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        using PIII=pair<int,int>;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<PIII,vector<PIII>,greater<PIII>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            int currTime=it.first;
            int node=it.second;
            pq.pop();
            if(currTime>dist[node]) continue;

            for(auto it:adj[node]){
                int next=it.first;
                int extra=it.second;
                if(dist[node]+extra<dist[next]){
                    dist[next]=dist[node]+extra;
                    pq.push({dist[next],next});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};