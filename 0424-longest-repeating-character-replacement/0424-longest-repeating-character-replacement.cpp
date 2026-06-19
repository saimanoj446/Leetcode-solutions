class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        vector<int> mp(26,0);
        int l=0;
        int replace=0;
        int maxcnt=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]-'A']++;
            maxcnt=max(maxcnt,mp[s[r]-'A']);
            replace=r-l+1-maxcnt;
            if(replace>k){
                mp[s[l]-'A']--;
                l++;
            }

        }
        return s.size()-l;
    }
};