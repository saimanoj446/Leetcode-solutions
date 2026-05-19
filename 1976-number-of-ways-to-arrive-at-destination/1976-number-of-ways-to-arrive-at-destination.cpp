class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        for(auto it: roads){
            int u=it[0];
            int v=it[1];
            long long wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<long long> time(n,1e18);
        time[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        using PIII=pair<long long,int>;//time,node
        priority_queue<PIII,vector<PIII>,greater<PIII>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (t > time[node]) continue;
            for(auto it: adj[node]){
                int v=it.first;
                long long wt=it.second;
                if(wt+t<time[v]){
                    time[v]=wt+t;
                    ways[v]=ways[node];
                    pq.push({time[v],v});
                }
                else if(wt+t==time[v]){
                    ways[v]=(ways[v]+ways[node])%1000000007LL;
                }
            }
        }
        return ways[n-1];
    }
};