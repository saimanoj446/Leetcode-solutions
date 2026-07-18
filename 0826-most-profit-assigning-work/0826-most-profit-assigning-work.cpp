class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        //we pair proft,difficulty and sort by difficulty
        //sort workers increasing order
        sort(worker.begin(),worker.end());
        
        int n=difficulty.size();
        vector<pair<int,int>> diff(n);
        for(int i=0;i<n;i++){
            diff[i].first=difficulty[i];
            diff[i].second=profit[i];
        }
        sort(diff.begin(),diff.end());
        //worker
        int m=worker.size();
        int j=0;
        int profitTotal=0;
        int temp=0;
        for(int i=0;i<m;i++){
            while(j<n && diff[j].first<=worker[i]){
                temp=max(temp,diff[j].second);
                j++;
            }
            profitTotal+=temp;
        }
        return profitTotal;

    }
};