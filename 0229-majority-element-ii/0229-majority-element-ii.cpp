class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int el1=INT_MIN; int cnt1=0;
        int el2=INT_MIN; int cnt2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && el1!=nums[i]){
                cnt2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]){
                cnt1++;
            }
            else if(el2==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int ch1=0; int ch2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) ch1++;
            if(nums[i]==el2) ch2++;
        }
        if(ch1>n/3) ans.push_back(el1);
        if(ch2>n/3) ans.push_back(el2);
        return ans;
    }
};