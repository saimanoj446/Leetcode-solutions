class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());
        unordered_map<int,int> mp;
        int rank=1;
        for(int i=0;i<n;i++){
            if(mp.find(copy[i])==mp.end()){
                mp[copy[i]]=rank++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};