class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posindex=0;
        int negindex=1;
        int n=nums.size();
        vector<int> arr(n,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                arr[posindex]=nums[i];
                posindex+=2;
            }
            else{
                arr[negindex]=nums[i];
                negindex+=2;
            }
        }
        return arr;
    }
};