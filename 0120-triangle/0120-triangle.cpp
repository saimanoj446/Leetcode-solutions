class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();//no.of rows
        int n= triangle[m-1].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            dp[m-1][i]=triangle[m-1][i];
        }
        //last before row to first row
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=(triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]));
            }
        }
        return dp[0][0];
    }
};