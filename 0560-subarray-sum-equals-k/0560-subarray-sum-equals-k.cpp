class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixCount;//sum
        prefixCount[0] = 1;
        int currsum=0;
        int totalsubarrays=0;
        for(int num:nums){
            currsum+=num;
            int target=currsum-k;
            if(prefixCount.find(target)!=prefixCount.end()){
                //found
                totalsubarrays+=prefixCount[target];
            }
            prefixCount[currsum]++;
        }
        return totalsubarrays;
    }
};