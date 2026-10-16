class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set <int> st;
        for(int it:nums){
            st.insert(it);
        }
        int cnt=0;
        int maxi=0;
        for(auto &it:st){
            if(st.find(it-1)==st.end()){
                cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};