class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long sum=0;
        long long maxi=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(i>=k){
                int left=nums[i-k];
                sum-=left;
                if(--mp[left]==0){
                    mp.erase(left);
                }
            }
            if(i>=k-1 && mp.size()==k){
                maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
};