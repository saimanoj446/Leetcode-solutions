class Solution {
public:
    void solve(vector<int>& nums,vector<int>& curr,int i, int n,vector<vector<int>> &result){
        if(i==n){
            result.push_back(curr);
            return;
        }
        //not choose
        solve(nums,curr,i+1,n,result);
        //choose
        curr.push_back(nums[i]);
        solve(nums,curr,i+1,n,result);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        int i=0;
        int n= nums.size();
        solve(nums,curr,i,n,result);
        return result;
    }
};