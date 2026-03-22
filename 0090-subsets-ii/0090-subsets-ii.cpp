class Solution {
public:
    void solve(int ind, int n,vector<int> &temp,vector<int>& nums,vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i= ind; i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,temp,nums,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        solve(0,n,temp,nums,ans);
        return ans;
    }
};