class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> money(3,0);
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) money[0]++;
            if(bills[i]==10){
                money[1]++;
                if(money[0]!=0){
                    money[0]--;
                }
                else return false;
            }
            if(bills[i]==20){
                money[2]++;
                if(money[1]!=0 && money[0]!=0){
                    money[0]--;
                    money[1]--;
                }
                else if(money[0]>=3){
                    money[0]-=3;
                }
                else return false;
            }
        }
        return true;
    }
};