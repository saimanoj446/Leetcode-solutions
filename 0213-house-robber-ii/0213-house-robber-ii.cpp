class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max({nums[0],nums[1],nums[2]});
        int prev=nums[0];
        int curr=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            int pick=nums[i]+prev;
            int not_pick=curr;
            int next=max(pick,not_pick);
            prev=curr;
            curr=next;
        }
        int way1=curr;

        prev=nums[1];
        curr=max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            int pick=nums[i]+prev;
            int not_pick=curr;
            int next=max(pick,not_pick);
            prev=curr;
            curr=next;
        }
        int way2=curr;
        return max(way1,way2);

    }
};