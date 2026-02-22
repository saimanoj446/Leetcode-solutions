class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        int  mini=INT_MAX;
        while(low<=high){
            mid=low+(high-low)/2;
            //left half sorted, so search right half
            if(nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            //right half sorted so search left half
            else{
                high=mid-1;
                mini=min(mini,nums[mid]);
            }
        }
        return mini;
    }
};