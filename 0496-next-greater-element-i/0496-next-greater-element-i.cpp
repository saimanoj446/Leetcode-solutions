class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        unordered_map<int, int> ngeMap;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if (st.empty()) ngeMap[nums2[i]] = -1;
            else ngeMap[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for (int num : nums1) {
            ans.push_back(ngeMap[num]);
        }
        return ans;
    }
};