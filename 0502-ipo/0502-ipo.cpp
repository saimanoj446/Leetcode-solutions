class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> comb(n);
        for(int i=0;i<n;i++){
            comb[i].first=capital[i];
            comb[i].second=profits[i];
        }
        sort(comb.begin(),comb.end());
        priority_queue<int> pq;//maxheap
        int i=0;
        while(k--){
            while(i<n && comb[i].first<=w){
                pq.push(comb[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};