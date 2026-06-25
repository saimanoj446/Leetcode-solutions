class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        dp[0]=nums[0];
        int curr=max(nums[0],nums[1]),prev=nums[0],next=0;
        for(int i=2;i<n;i++){
            int pick=prev+nums[i];
            int not_pick=curr;
            next=max(pick,not_pick);
            prev=curr;
            curr=next;
        }
        return curr;
    }
};