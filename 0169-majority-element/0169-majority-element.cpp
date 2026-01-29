class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1;
        for(int i=0;i<n;i++){
            if(nums[i]==el) cnt1++;
        }
        if(cnt1>=n/2) return el;
        else return -1;
    }
};