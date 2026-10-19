class Solution {
public:
    long long func(vector<int>&piles, int mid){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count+=(piles[i]+mid-1)/mid;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};