class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>str;
        for(auto it: s){
            if(97<=it && it<=122){
                str.push_back(it);
            }
            else if (65<=it && it<=90){
                str.push_back(it+32);
            }
            else if (48<=it && it<=57){
                str.push_back(it);
            }
        }
        vector<char> rev=str;
        reverse(rev.begin(),rev.end());
        return str==rev;
    }
};