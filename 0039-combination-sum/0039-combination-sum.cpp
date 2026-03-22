class Solution {
public:
    void solve(int ind,int target,int n,vector<int>& candidates,vector<int> &temp,vector<vector<int>> &ans){
        //base case
        if(ind==n){
            if(target==0){
                ans.push_back(temp);
                return;
            }
            else return;
        }
        //pick
        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],n,candidates,temp,ans);
            temp.pop_back();
        }
        //notpick
        solve(ind+1,target,n,candidates,temp,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n= candidates.size();
        vector<int> temp;
        solve(0,target,n,candidates,temp,ans);
        return ans;
    }
};