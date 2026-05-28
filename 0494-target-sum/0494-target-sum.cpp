class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_pick=solve(ind-1,target,nums,dp);
        int pick = 0;
        if(target>=nums[ind]) pick=solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=(pick+not_pick);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if ((sum + target) % 2 != 0 || abs(target) > sum) return 0;
        int x=(target+sum)/2;
        vector<vector<int>> dp(nums.size(),vector<int>(x+1,-1));
        return solve(nums.size()-1,x,nums,dp);
    }
};