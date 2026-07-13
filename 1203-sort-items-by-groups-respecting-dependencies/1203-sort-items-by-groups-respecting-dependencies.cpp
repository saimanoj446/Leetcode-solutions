class Solution {
public:
    vector<int> toposort(vector<vector<int>>& adj, vector<int>& indegree, int size) {
        vector<int> res;
        queue<int> q;
        
        for(int i = 0; i < size; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            
            for(int next : adj[curr]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        // If we couldn't sort all elements, a cycle exists.
        return res.size() == size ? res : vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1) {
                group[i]=m;
                m++;
            }
        }
        vector<vector<int>> adjItem(n);
        vector<int> indegreeItem(n,0);

        
        vector<vector<int>> adjGroup(m);
        vector<int> indegreeGroup(m,0);
        for(int i=0;i<n;i++){
            for(auto it:beforeItems[i]){
                adjItem[it].push_back(i);
                indegreeItem[i]++;
                if(group[it]!=group[i]){
                    adjGroup[group[it]].push_back(group[i]);
                    indegreeGroup[group[i]]++;
                }
            }
        }
        vector<int> itemOrder = toposort(adjItem, indegreeItem, n);
        vector<int> groupOrder = toposort(adjGroup, indegreeGroup, m);
        
        // If either topological sort fails (cycle detected), return empty array
        if(itemOrder.empty() || groupOrder.empty()) {
            return {};
        }
        vector<vector<int>> orderedGroups(m);
        for(auto it:itemOrder){
            orderedGroups[group[it]].push_back(it);
        }
        vector<int> ans;
        for(auto g:groupOrder){
            for(auto it:orderedGroups[g]){
                ans.push_back(it);
            }
        }
        return ans;

    }
};