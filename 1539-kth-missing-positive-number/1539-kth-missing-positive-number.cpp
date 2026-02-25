class Solution {
public:
    int func(vector<int>& arr,int i){
        return arr[i]-i-1;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(func(arr,mid)>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low+k;
    }
};