class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            //low and high same
            if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            //right half sorted
            else if(nums[mid]<=nums[high]){
                if(nums[mid]<target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(nums[low]<=target && target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return false;
    }
};