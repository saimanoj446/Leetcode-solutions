class Solution {
public:
    void solve(int ind,int target,int n,vector<int>& candidates,vector<int> &temp,vector<vector<int>> &ans){
        //base case
        if(target==0){
            ans.push_back(temp);
            return;
        }
        //pick
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                solve(i+1,target-candidates[i],n,candidates,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n= candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,target,n,candidates,temp,ans);
        return ans;
    }
};