class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int currlen=1;
        int maxi=1;
        unordered_set<int>st;
        for(auto it: nums){
            st.insert(it);
        }
        for(auto it: st){
            if(st.find(it-1)!=st.end()){
                continue;
            }
            else{
                int i=1;
                int currlen=1;
                while(st.find(it+i)!=st.end()){
                    currlen++;
                    i++;
                }
                maxi=max(maxi,currlen);
            }
        }
        return maxi;

    }
};