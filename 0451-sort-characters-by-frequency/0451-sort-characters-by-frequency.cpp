class Solution {
public:
    string frequencySort(string s) {
        vector<int> mp(128,0);
        for(char it:s){
            mp[it]++;
        }
        sort(s.begin(),s.end(),[&mp](char a,char b){
            if(mp[a]==mp[b]) return a<b;
            return mp[a]>mp[b];
        });
        return s;
    }
};