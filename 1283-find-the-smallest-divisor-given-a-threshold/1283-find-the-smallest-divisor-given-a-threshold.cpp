class Solution {
public:
    int ceil(int n,int m){
        return (n+m-1)/m;
    }
    int func(vector<int>& nums,int div){
        int n= nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=ceil(nums[i],div);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int divisor=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(nums,mid)<=threshold){
                divisor=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return divisor;
    }
};