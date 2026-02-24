class Solution {
public:
    int func(vector<int>&bloomDay,int k,int mid){
        int n=bloomDay.size();
        int count=0;
        int boquets=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
                if(count==k){
                    boquets++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        return boquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*m*k>n){
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(bloomDay,k,mid)>=m){
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