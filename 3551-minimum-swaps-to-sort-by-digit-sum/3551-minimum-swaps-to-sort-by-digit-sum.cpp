class Solution {
public:
    int sum(int num){
            int req=0;
            while(num>0){
                req=req+(num%10);
                num=num/10;
            }
            return req;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> dig;
        dig=nums;
        sort(dig.begin(),dig.end(),[&](int a, int b){
            int sa = sum(a), sb= sum(b);
            return sa!=sb ? sa<sb : a<b;
        });
        unordered_map<int,int> pos;
        //map value->target index
        for(int i=0;i<n;i++){
            pos[dig[i]]=i;
        }
        //vis array for cycle detection
        vector<bool> visited(n,false);
        int swaps=0;
        for(int i=0;i<n;i++){
            if(visited[i] || pos[nums[i]]==i) continue;
            int cycle_len=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=pos[nums[j]];
                cycle_len++;
            }
            swaps+=cycle_len-1;
        }
        return swaps;
    }

};