class Solution {
public:
    bool validPalindrome(string &s, int a, int b){
        int l=a;
        int r=b;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return validPalindrome(s,l,r-1)||validPalindrome(s,l+1,r);
            }
            l++;
            r--;
        }
        return true;
    }
};