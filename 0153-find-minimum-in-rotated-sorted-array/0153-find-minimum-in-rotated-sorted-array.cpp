class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int mini=INT_MAX;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            //right half sorted
            if(nums[mid]<=nums[high]){
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
            else{
                mini=min(mini,nums[low]);
                low=mid+1;
            }
        }
        return mini;
    }
};