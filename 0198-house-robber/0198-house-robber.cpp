class Solution {
public:
    int func(int ind,vector<int> &dp,vector<int>& nums){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=func(ind-2,dp,nums)+nums[ind];
        int not_pick=func(ind-1,dp,nums);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return func(n-1,dp,nums);

    }
};