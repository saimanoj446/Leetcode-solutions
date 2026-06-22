class Solution {
public:
    bool f(string &s,int ind,int count,vector<vector<int>> &dp){
        if(count<0) return false;
        if(ind==s.size()) return (count==0);
        if(dp[ind][count]!=-1) return dp[ind][count];
        if(s[ind]=='(') return dp[ind][count]=f(s,ind+1,count+1,dp);
        if(s[ind]==')') return dp[ind][count]=f(s,ind+1,count-1,dp);
        else return dp[ind][count]=(f(s,ind+1,count+1,dp) || f(s,ind+1,count-1,dp) || f(s,ind+1,count,dp));
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(s,0,0,dp);
    }
};