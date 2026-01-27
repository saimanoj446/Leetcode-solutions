class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Better soln
        sort(nums.begin(),nums.end());
        int longest=0;
        int cntcurr=0;
        int lastsmaller=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==lastsmaller){
                cntcurr++;
                lastsmaller=nums[i];
            }
            else if(nums[i]!=lastsmaller){
                cntcurr=1;
                lastsmaller=nums[i];
            }
            longest=max(cntcurr,longest);
        }
        return longest;
    }
};