class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26,0);
        int l=0;
        int maxcnt=0;
        int maxi=0;
        int replace=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]-'A']++;
            maxcnt=max(maxcnt,mp[s[r]-'A']);
            while(r-l+1-maxcnt>k){
                mp[s[l]-'A']--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};