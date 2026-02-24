class Solution {
public:
    int func(vector<int>& weights, int mid){
        int sum=0;
        int n=weights.size();
        int count=1;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>mid){
                count++;
                sum=weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int answer=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(weights,mid)<=days){
                answer=mid;
                high=mid-1;  
            }
            else{
                low=mid+1;
            }
        }
        return answer;
    }
};