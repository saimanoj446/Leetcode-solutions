class Solution {
public:
long long func(vector<int>&piles,int k){
    long long count=0;
    for(int it:piles){
        count+=it/k;
        if(it%k>0) count++;
    }
    return count;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int ans=-1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};