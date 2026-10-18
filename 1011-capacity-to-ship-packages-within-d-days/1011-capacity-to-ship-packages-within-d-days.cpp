class Solution {
public:
    int func(vector<int>& weights, int mid){
        int days=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                days++;
                sum=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(auto it:weights){
            sum+=it;
        }
        int ans=0;
        int high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(weights,mid)<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};