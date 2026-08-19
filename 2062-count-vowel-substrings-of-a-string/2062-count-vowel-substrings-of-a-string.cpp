class Solution {
public:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    int countVowelSubstrings(string word) {
        int n=word.size();
        int l=0;
        int lastConsonant=-1;
        int cnt=0;
        unordered_map<char,int> mp;
        for(int r=0;r<n;r++){
            if(!isVowel(word[r])){
                lastConsonant=r;
                mp.clear();
            }
            else{
                mp[word[r]]=r;
                if(mp.size()==5){
                    int min_vowel=min({mp['a'],mp['e'],mp['i'],mp['o'],mp['u']});
                    cnt+=(min_vowel-lastConsonant);

                }
            }
        }
        return cnt;
    }
};