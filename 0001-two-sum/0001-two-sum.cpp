class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        int rem=0;
        for(int i=0;i<n;i++){
            rem=target-nums[i];
            //found in mp
            if(mp.find(rem)!=mp.end()){
                int j=mp[rem];
                return {i,j};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};