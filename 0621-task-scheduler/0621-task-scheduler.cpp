class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(auto it: tasks){
            mp[it-'A']++;
        }
        priority_queue<int> pq;
        int time=0;
        for(auto it:mp){
            if(it!=0){
                pq.push(it);
            }
        }
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(auto it: temp){
                if(it>0) pq.push(it);
            }
            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};