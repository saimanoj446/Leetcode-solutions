class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        int n1=nums1.size();
        int n2=nums2.size();
        sort(nums2.begin(),nums2.end());
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else {
                ans.push_back(nums1[i]);
                i++;
                j++;
                while(i<n1&&nums1[i]==nums1[i-1]) i++;
                while(j<n2&&nums2[j]==nums2[j-1]) j++;
            }
        }
        return ans;
    }
};