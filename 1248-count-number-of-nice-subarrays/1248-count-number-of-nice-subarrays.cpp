class Solution {
public:
    int atmost(vector<int> & nums, int k){
        int l=0;
        int count=0;
        int subarrcnt=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2!=0){ 
                count++;
            }
            while(count>k){
                if(nums[l]%2!=0){
                    count--;
                }
                l++;
            }
            subarrcnt+= r-l+1;
        }
        return subarrcnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};