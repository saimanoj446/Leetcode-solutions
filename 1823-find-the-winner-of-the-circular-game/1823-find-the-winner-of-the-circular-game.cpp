class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> list;
        for(int i=1;i<=n;i++){
            list.push_back(i);
        }
        int startIndex=0;
        while(list.size()>1){
            int removalIndex=(startIndex+k-1)%list.size();
            list.erase(list.begin()+removalIndex);
            startIndex=removalIndex;
        }
        return list.front();
    }
};