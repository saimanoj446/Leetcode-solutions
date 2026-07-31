class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>> ans;
        for(auto &it:strs){
            vector<int> count(26,0);
            for(auto ch: it){
                count[ch-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+="#"+to_string(count[i]);
            }
            mp[key].push_back(it);
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};