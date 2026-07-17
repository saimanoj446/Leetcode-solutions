class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,INT_MAX);
        ans[0]=0;
        for(int i=0;i<n;i++){
            if (ans[i] == INT_MAX) continue;
            int range=nums[i];
            for(int j=i+1;j<=i+range && j<n;j++){
                ans[j]=min(1+ans[i],ans[j]);
            }
        }
        return ans[n-1];
    }
};