class Solution {
public:
    int climbStairs(int n,vector<int> &memo) {
        if(memo[n]!=-1) return memo[n];
        return memo[n]=climbStairs(n-1,memo)+climbStairs(n-2,memo);
    }
    int climbStairs(int n){
        vector<int> memo(n+1,-1);
        memo[0]=1;memo[1]=1;
        return climbStairs(n,memo);
    }
};