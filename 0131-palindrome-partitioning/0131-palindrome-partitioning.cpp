class Solution {
public:
    bool isPalindrome(string s,int start, int end){
        int n= s.length();
        int low=start; int high=end;
        while(low<high){
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    void solve(int ind,int n,string &s,vector<string> &tempvec,vector<vector<string>> &ans){
        if(ind==n){
            ans.push_back(tempvec);
        }

        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                tempvec.push_back(s.substr(ind,i-ind+1));
                solve(i+1,n,s,tempvec,ans);
                tempvec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tempvec;
        string temp="";
        int n= s.length();
        solve(0,n,s,tempvec,ans);
        return ans;
    }
};