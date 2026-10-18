class Solution {
public:
    int findlow(vector<int>& nums, int target){
        int low=0;
        int ans=-1;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int findhigh(vector<int>& nums, int target){
        int low=0;
        int ans=-1;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=findlow(nums,target);
        int high=findhigh(nums,target);
        return {low,high};
    }
};