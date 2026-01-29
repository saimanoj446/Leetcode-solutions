class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        int presum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];

            presum=sum-k;
            if(mpp.find(presum)!=mpp.end()){
                cnt+=mpp[presum];
            }

            mpp[sum]++;
        }
        return cnt;
    }
};