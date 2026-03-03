class Solution {
public:
    int solve(string &s, int i, long current, int sign){
        if(i>=s.length() || !isdigit(s[i])){
            return (int)(current*sign);
        }
        int digit=s[i]-'0';
        if (sign == 1) {
            if (current > INT_MAX / 10 || (current == INT_MAX / 10 && digit > 7)) return INT_MAX;
        } else {
            if (current > INT_MAX / 10 || (current == INT_MAX / 10 && digit > 8)) return INT_MIN;
        }
        return solve(s,i+1,current*10+digit,sign);
    }
    int myAtoi(string s) {
        int n= s.length();
        int i=0;
        while(i<n && s[i]==' ') i++;

        //sign
        int sign =1;
        if(i<n && ((s[i]=='+')||(s[i]=='-'))){
            if(s[i]=='-'){
                sign = -1;
            }
            else{
                sign = 1;
            }
            i++;
        }
        return solve(s,i,0,sign);
    }
};