class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        function<int(int)> solve = [&](int i){
            if(i<0) return 0;
            if(memo[i]!=-1) return memo[i];
            int pick= nums[i]+ solve(i-2);
            int not_pick=solve(i-1);
            return memo[i]= max(pick,not_pick);
        };
        return solve(nums.size()-1);
    }
};