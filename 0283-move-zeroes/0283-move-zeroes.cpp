class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;//writer
        for(int i=0;i<nums.size();i++){//reader
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;//update writer to next position
            }
        }
    }
};