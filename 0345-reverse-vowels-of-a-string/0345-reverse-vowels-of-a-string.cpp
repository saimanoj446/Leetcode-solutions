class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    string reverseVowels(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(l<r){
            while (l < r && !isVowel(s[l])) {
                l++;
            }
            while (l < r && !isVowel(s[r])) {
                r--;
            }
            if(l<r){
                swap(s[r],s[l]);
                l++;
                r--;
            }
        }
        return s;
    }
};