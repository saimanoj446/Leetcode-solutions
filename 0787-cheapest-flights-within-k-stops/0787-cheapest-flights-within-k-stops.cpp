class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> cost(n,1e9);
        //cost array has the cheapest way to reach every node
        //pq : {k, { node, dist }}
        // 1. Define the type clearly once at the top of your function
        using PIII = pair<int, pair<int, int>>;
        queue<PIII> q;
        cost[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node = q.front().second.first;
            int price= q.front().second.second;
            q.pop();
            if (stops > k) continue;
            for(auto it: adj[node]){
                int v= it.first;
                int wt=it.second;
                if(wt+price<cost[v]){
                    cost[v]=wt+price;
                    q.push({stops+1,{v,cost[v]}});
                }
            }
        }
        if(cost[dst]==1e9) return -1;
        else return cost[dst];
    }
};