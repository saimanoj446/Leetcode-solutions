class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
        int prefixsum=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(prefixsum==k) count++;
            int rem=prefixsum-k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[prefixsum]++;
        }
        return count;
    }
};