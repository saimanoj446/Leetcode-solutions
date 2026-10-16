class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el=-1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                el=nums[i];
                cnt=1;
            }
            else{
                if(nums[i]==el){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        //we have el,check if its > n/2
        return el;

    }
};