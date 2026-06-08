class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int count=0;
        int presum=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            presum+=nums[i];
            if(presum==k) count++;
            int rem=presum-k;
            if(mp.find(rem)!=mp.end()) count+=mp[rem];
            mp[presum]++;
        }
        return count;
    }
};