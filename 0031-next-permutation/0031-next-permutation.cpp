class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n= nums.size();
        //finding index where first dip occurs from n-1
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        //no dip is found
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //now swap ind and least elem > ind, we already have increasig order so no need to sort
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        //now reverse arr[ind] to arr[n]
        reverse(nums.begin()+ind+1,nums.end());
    }
};