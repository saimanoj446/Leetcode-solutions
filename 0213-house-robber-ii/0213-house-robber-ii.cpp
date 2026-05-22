class Solution {
public:
    int solve(int i,int start,int end,vector<int> &dp, vector<int> & nums){
        if(i<start) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i]+solve(i-2,start,end,dp,nums);
        int not_pick = solve(i-1,start,end,dp,nums);
        return dp[i]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int case1 = solve(n-1,1,n-1,dp1,nums);
        int case2 = solve(n-2,0,n-2,dp2,nums);
        return max(case1,case2);
    }
};