class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int p=k;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(p+1,vector<int>(2,0)));
        for(int k=0;k<p+1;k++){
            if(k==0){
                dp[0][k][1]=-1e9;
                dp[0][k][0]=0;
            }
            else{
                dp[0][k][0]=0;
                dp[0][k][1]=-prices[0];
            }
        }
        for(int i=1;i<n;i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = -1e9;
            for(int k=1;k<p+1;k++){
                dp[i][k][0]=max(dp[i-1][k][0],prices[i]+dp[i-1][k][1]);
                dp[i][k][1]=max(dp[i-1][k][1],-prices[i]+dp[i-1][k-1][0]);
            }
        }
        return dp[n-1][p][0];
    }
};