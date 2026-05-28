class Solution {
public:
    int solve(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target % coins[0]==0) return target/coins[0];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take=0+solve(ind-1,target,coins,dp);
        int take=1e9;
        if(target>=coins[ind]) take=1+solve(ind,target-coins[ind],coins,dp);
        return dp[ind][target]=min(not_take,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int result=solve(coins.size()-1,amount,coins,dp);
        if(result>=1e9) return -1;
        return result;
    }
};