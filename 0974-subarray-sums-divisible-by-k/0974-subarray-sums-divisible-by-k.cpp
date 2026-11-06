class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int presum=0;
        int count=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int req=((presum % k)+k)%k;
            if(mp.find(req)!=mp.end()){
                count+=mp[req];
            }
            mp[req]++;
        }
        return count;
    }
};