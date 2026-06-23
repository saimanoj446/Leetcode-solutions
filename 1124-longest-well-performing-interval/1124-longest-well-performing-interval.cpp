class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int presum=0;
        int maxi=0;
        unordered_map <int,int> mp;
        for(int i=0;i<hours.size();i++){
            if(hours[i]>8) presum++;
            else presum--;
            if(presum>0){
                maxi=i+1;
            }
            else{
                int rem=presum-1;
                if(mp.find(rem)!=mp.end()){
                    maxi=max(maxi,i-mp[rem]);
                }
            }
            if(mp.find(presum)==mp.end()){
                mp[presum]=i;
            }
        }
        return maxi;
    }
};