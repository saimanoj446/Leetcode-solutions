class Solution {
public:
    void solve(int n, string s,int open, int close,vector<string>&result){
        if(s.length()==2*n){
            result.push_back(s);
            return;
        }
        if (open<n){
            solve(n,s+'(',open+1,close,result);
        }
        if(close<open){
            solve(n,s+')',open, close+1,result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n,"",0,0,result);
        return result;
    }
};