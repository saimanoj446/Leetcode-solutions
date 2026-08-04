class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int j=0;j<=n;j++){
            int cnt=0;
            for(int i=0;i<32;i++){
                if((j&(1<<i))!=0) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};