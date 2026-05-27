class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(i==triangle.size()) return 0;
        if(dp[i][j]!=1e9) return dp[i][j];
        int one= solve(i+1,j,triangle,dp);
        int two= solve(i+1,j+1,triangle,dp);
        return dp[i][j]=(triangle[i][j]+min(one,two));

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n= triangle[m-1].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        return solve(0,0,triangle,dp);
    }
};