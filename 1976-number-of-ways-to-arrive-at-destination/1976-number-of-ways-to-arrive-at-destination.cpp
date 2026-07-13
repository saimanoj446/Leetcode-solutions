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
        vector<long long>time(n,LLONG_MAX);
        time[0]=0;
        vector<int> ways(n,0);
        ways[0]=1;
        using PIII=pair<long long,int>;//mintime,node
        priority_queue<PIII,vector<PIII>,greater<PIII>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            long long currTime=it.first;
            int currNode=it.second;
            pq.pop();
            if(currTime>time[currNode]) continue;
            for(auto it:adj[currNode]){
                int nextNode=it.first;
                long long wt=it.second;
                if(currTime+wt<time[nextNode]){
                    time[nextNode]=currTime+wt;
                    ways[nextNode]=ways[currNode];
                    pq.push({time[nextNode],nextNode});
                }
                else if(currTime+wt==time[nextNode]){
                    ways[nextNode]=(ways[nextNode]+ways[currNode])%1000000007;
                }
            }
        }
        return ways[n-1];
    }
};