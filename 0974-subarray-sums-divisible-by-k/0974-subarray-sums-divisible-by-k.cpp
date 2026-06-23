class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int presum=0;
        int count=0;
        unordered_map<int,int> mp;//remainder,frequency
        mp[0]=1;//presum0 means remainder 0 occured once
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int rem=(presum%k+k)%k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};