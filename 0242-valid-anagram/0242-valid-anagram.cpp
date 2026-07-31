class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(int i=0;i<s.size();i++){
            mp1[s[i]-'a']++;
            mp2[t[i]-'a']++;
        }
        return mp1==mp2;
    }
};