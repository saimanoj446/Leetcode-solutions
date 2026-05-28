class Solution {
public:
bool solve(int ind, int target, vector<int>& nums,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(ind==0) return nums[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool not_take=solve(ind-1,target,nums,dp);
        bool take=false;
        if(target>=nums[ind]) take= solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=(int)(take | not_take);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,sum/2,nums,dp);
    }
};