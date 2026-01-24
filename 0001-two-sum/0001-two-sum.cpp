class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            int more= target-nums[i];
            if(hash.find(more)!=hash.end()){
                return {hash[more],i};
            }
            hash[nums[i]]=i;
        }
        return {0,0};
    }
};