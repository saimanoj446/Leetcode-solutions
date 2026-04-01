class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        int l=0;
        int r=n-1;
        //find initial sum
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int k_sum=sum;
        for(int i=k-1;i>=0;i--){
            sum=sum+cardPoints[r]-cardPoints[i];
            k_sum=max(sum,k_sum);
            r--;
        }
        return k_sum;
    }
};