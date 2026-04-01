class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        unordered_map<char,int> map;
        int r=0;
        int len=0;
        int max_len=0;
        for(int r=0;r<n;r++){
            if(map.find(s[r])!= map.end() && map[s[r]]>=l){
                //s[r] in hashmap, so change l
                l=map[s[r]]+1;
            }
            map[s[r]]=r;
            max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};