class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==0) return 0;
        int i=1;
        int sum=1;
        while(i<n){
            //plateau
            if(ratings[i]==ratings[i-1]) {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>=peak){
                sum=sum+down-peak;
            }
        }
        return sum;
    }
};