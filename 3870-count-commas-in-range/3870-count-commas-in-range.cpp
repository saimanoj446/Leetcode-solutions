class Solution {
public:
    int func(int a,int b,int n){
        return (n>=a && n<=b);
    }
    int countCommas(int n) {
        int count=0;
        if(func(1000,999999,n)) count+=(n-1000+1);
        return count;
    }
};