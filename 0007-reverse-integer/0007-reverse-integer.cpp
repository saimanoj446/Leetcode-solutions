class Solution {
public:
    int reverse(int x) {
        int revno=0;
        int lastdig;
        while(x!=0){
            lastdig=x%10;
            x=x/10;
            if(revno>INT_MAX/10){
                return 0;
            }
            if(revno<INT_MIN/10){
                return 0;
            }
            revno=revno*10+lastdig;
        }
        return revno;
    }
};