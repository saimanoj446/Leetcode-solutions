class Solution {
public:
    int mirrorFrequency(string s) {
        int n= s.size();
        vector<int> mp1(10,0);//0 to 9
        vector<int> mp2(26,0);//a to z
        for(int i=0;i<n;i++){
            if(s[i]>=48 && s[i]<=57){
                mp1[s[i]-48]++;
            }
            if(s[i]>=97 && s[i]<=122){
                mp2[s[i]-97]++;
            }
        }
        int sum=0;
        for(int i=0;i<5;i++){
            sum+=abs(mp1[i]-mp1[9-i]);
        }
        for(int i=0;i<13;i++){
            sum+=abs(mp2[i]-mp2[25-i]);
        }
        return sum;
    }
};