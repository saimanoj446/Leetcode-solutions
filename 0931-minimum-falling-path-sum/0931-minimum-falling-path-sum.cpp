class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if (j < 0 || j >= matrix.size()) return 1e9;
        if(i==matrix.size()) return 0;
        if (dp[i][j] != 1e9) return dp[i][j];
        int one= solve(i+1,j-1,matrix,dp);
        int two= solve(i+1,j,matrix,dp);
        int three= solve(i+1,j+1,matrix,dp);        
        return dp[i][j]=(matrix[i][j]+min({one,two,three}));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int i=0;i<n;i++){
            mini=min(mini,solve(0,i,matrix,dp));
        }
        return mini;
    }
};