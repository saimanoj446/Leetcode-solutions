class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int low=0;
        int high =n-1;
        int lb=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                high=mid-1;
                lb=min(lb,mid);
            }
            if(nums[mid]<target){
                low=mid+1;
            }
        }
        return lb;
    }
};