class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;//element, last seen index
        int l=0;
        int maxi=0;
        for(int r=0;r<n;r++){
            char curr=s[r];
            if(mp.find(curr)!=mp.end()&& mp[curr]>=l){
                l=mp[curr]+1;
            }
            mp[curr]=r;
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};