class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int presum=0;
        int maxi=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) presum++;
            else presum--;
            if(presum==0){
                maxi=max(maxi,i+1);
            }
            if(mp.find(presum)!=mp.end()){
                maxi=max(maxi,i-mp[presum]);
            }
            else mp[presum]=i;
        }
        return maxi;
    }
};