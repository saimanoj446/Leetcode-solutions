class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=0;
        int el2=0;
        int cnt1=0;
        vector<int> ans;
        int cnt2=0;
        int n=nums.size();
        int target=n/3;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                cnt1++;
            }
            else if(nums[i]==el2){
                cnt2++;
            }
            else if(cnt1==0){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                el2=nums[i];
                cnt2=1;
            }
             
            else {
                cnt1--;
                cnt2--;
            }
        }
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
        }
        if(count1>target) ans.push_back(el1);
        if(count2>target) ans.push_back(el2);
        return ans;
    }
};