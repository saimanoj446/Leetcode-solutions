class Solution {
public:
    void solve(int ind, int k, int n, vector<int> &temp,vector<vector<int>> &ans){
        if(k==0){
            if(n==0){
                ans.push_back(temp);
                return;
            }
            return;
        }
        if (ind > 9) {
            return;
        }
        //pick
        if(k>0 && ind<=n){
            temp.push_back(ind);
            solve(ind+1,k-1,n-ind,temp,ans);
            temp.pop_back();
        }
        //not pick
        solve(ind+1,k,n,temp,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,k,n,temp,ans);
        return ans;
    }
};