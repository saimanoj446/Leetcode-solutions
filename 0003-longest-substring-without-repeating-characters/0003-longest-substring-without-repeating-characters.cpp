class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int maxi=0;
        vector<int> mp(128,0);
        for(int i=0;i<s.size();i++){
            while(mp[s[i]] > 0){
                mp[s[l]]--;
                l++;
            }
            mp[s[i]]++;
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};