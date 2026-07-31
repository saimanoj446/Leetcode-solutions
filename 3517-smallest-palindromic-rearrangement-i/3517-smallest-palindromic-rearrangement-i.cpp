class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string ans;
        string single_el="";
        ans=s.substr(0,n/2);
        if(n%2!=0) single_el=s[n/2];
        sort(ans.begin(),ans.end());
        string temp=ans;
        reverse(temp.begin(),temp.end());
        return ans+single_el+temp;
    }
};