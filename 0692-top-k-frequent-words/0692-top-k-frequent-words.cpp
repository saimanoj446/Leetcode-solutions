class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words){
            mp[it]++;
        }
        vector<string> unique_words;
        for(auto it:mp){
            unique_words.push_back(it.first);
        }
        sort(unique_words.begin(),unique_words.end(),[&mp](string a,string b){
            if(mp[a]!=mp[b]){
                return mp[a]>mp[b];
            }
            return a<b;
        });
        return vector<string>(unique_words.begin(),unique_words.begin()+k);
    }
};