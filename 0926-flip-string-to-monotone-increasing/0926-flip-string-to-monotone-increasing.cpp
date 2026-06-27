class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int ones_count=0;
        if(s[0]=='1') ones_count++;
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                dp[i]=dp[i-1];
                ones_count++;
            }
            else{
                dp[i]=min(1+dp[i-1],ones_count);
            }
        }
        return dp[n-1];
    }
};