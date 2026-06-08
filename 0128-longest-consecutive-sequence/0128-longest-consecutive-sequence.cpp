class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int currlen=1;
        int maxi=1;
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                currlen=1;
                int x=it;
            while(st.find(x+1)!=st.end()){
                currlen++;
                x++;
                }
                maxi=max(maxi,currlen);
            }
            
        }
        return maxi;
    }
};