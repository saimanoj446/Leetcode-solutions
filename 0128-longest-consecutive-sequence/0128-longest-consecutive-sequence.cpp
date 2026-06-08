class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int longest=1;
        int prev=nums[0];
        int n=nums.size();
        int currlen=1;
        for(int i=0;i<n;i++){
            if(nums[i]-1 == prev ){
                currlen++;
                prev=nums[i];
            }
            else if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            else{
                currlen=1;
                prev = nums[i];
            }
            longest=max(longest,currlen);
        }
        return longest;
    }
};