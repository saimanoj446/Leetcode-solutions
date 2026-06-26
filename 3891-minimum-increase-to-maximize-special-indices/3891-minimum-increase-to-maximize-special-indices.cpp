class Solution {
public:
    long long getCost(vector<int>& nums,int i){
        if(i<=0||i>=nums.size()-1) return 0;
        int target=max(nums[i+1],nums[i-1])+1;
        return max(0,target-nums[i]);
    }
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        long long count=0;
        if(n%2!=0){
            //odd length
            for(int i=1;i<n-1;i=i+2){
                count+=getCost(nums,i);
            }
            return count;
        }
        vector<vector<long long>> dp(n+3,vector<long long>(2,0));
        for(int i=n-2;i>=1;i--){
            long long curr_cost=getCost(nums,i);
            dp[i][1]=curr_cost+dp[i+2][1];
            long long skip_now=curr_cost+dp[i+3][1];
            long long dont_skip=curr_cost+dp[i+2][0];
            dp[i][0]=min(skip_now, dont_skip);
        }
        return min(dp[1][0],dp[2][1]);
    }
};