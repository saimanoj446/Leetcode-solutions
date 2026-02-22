class Solution {
public:
    long long func(vector<int>& piles, int k){
        int n=piles.size();
        long long time=0;
        for (int i=0;i<n;i++){
            time+=(piles[i]+k-1)/k;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
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