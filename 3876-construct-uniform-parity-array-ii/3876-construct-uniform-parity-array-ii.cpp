class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;//smallest odd number
        for(auto it: nums1){
            if(it%2!=0) mini= min(mini,it);
        }
        if(mini==INT_MAX) return true;
        for(auto it: nums1){
            if(it%2==0 && it<mini) return false;
        }
        return true;
    }
};