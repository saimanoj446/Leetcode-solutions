class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0&&j==0) return dp[i][j]=1;
        if(i<0||j<0) return dp[i][j]=0;
        int up=0; int left=0;
        if(i>=1) up=solve(i-1,j,dp);
        if(j>=1) left=solve(i,j-1,dp);
        return dp[i][j]=(up+left);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        solve(m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};