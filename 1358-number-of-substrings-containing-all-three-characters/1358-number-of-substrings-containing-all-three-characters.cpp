class Solution {
public:
    bool isValid(char c){
        return (c=='a'||c=='b'||c=='c');
    }
    int numberOfSubstrings(string s) {
        unordered_map<char,int> last_seen;
        int n=s.size();
        int lastnonvalid=-1;
        int cnt=0;
        for(int r=0;r<n;r++){
            if(!isValid(s[r])){
                lastnonvalid=r;
                last_seen.clear();
            }
            else{
                last_seen[s[r]]=r;
                if(last_seen.size()==3){
                    int min_valid=min({last_seen['a'],last_seen['b'],last_seen['c']});
                    cnt+=(min_valid-lastnonvalid);
                }
            }

        }
        return cnt;
    }
};