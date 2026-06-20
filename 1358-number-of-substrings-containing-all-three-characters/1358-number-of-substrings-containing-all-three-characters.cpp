class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3,0);
        int n=s.size();
        int l=0;
        int subarrcnt=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]-'a']++;
            while(mp[0]>=1 && mp[1]>=1 && mp[2]>=1){
                subarrcnt+=(n-r);
                mp[s[l]-'a']--;
                l++;
            }
        }
        return subarrcnt;
    }
};