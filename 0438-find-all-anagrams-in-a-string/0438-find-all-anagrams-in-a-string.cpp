class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int np= p.size();
        int ns=s.size();
        if(ns<np) return {};
        vector<int> p_count(26,0);
        vector<int> s_count(26,0);
        for(int i=0;i<np;i++){
            p_count[p[i]-'a']++;
            s_count[s[i]-'a']++;
        }
        if(p_count==s_count){
            ans.push_back(0);
        }
        for(int i=np;i<ns;i++){
            s_count[s[i]-'a']++;
            s_count[s[i-np]-'a']--;
            if(s_count==p_count) ans.push_back(i-np+1);
        }
        return ans;
    }
};