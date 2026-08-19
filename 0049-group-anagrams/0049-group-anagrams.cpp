class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto & it:strs){
            string it2=it;
            sort(it2.begin(),it2.end());
            mp[it2].push_back(it);
        }
        for(auto &it:mp){
            vector<string> temp;
            for(auto &it2:it.second){
                temp.push_back(it2);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};