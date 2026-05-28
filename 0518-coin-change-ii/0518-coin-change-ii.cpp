class Solution {
public:
    int solve(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if (target == 0) return 1;
        if(ind==0){
            if(target % coins[0]==0) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take=solve(ind-1,target,coins,dp);
        int take=0;
        if(target>=coins[ind]) take=solve(ind,target-coins[ind],coins,dp);
        return dp[ind][target]=not_take+take;
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int result=solve(coins.size()-1,amount,coins,dp);
        return result;
    }
};