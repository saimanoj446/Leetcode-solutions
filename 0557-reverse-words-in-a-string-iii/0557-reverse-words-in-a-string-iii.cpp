class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0,r=0,l=0;
        while(r<n){
            while(r<n&& s[r]!=' ') r++;
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                r++;
                l=r;
            }
        }
        return s;
    }
};