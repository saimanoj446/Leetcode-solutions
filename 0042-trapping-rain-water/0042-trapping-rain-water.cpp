class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int n=height.size();
        int total=0;
        int r=n-1;
        int leftMax=0;
        int rightMax=0;
        while(l<r){
            if(height[l]<=height[r]){
                //move left
                if(height[l]<leftMax) total+=leftMax-height[l];
                leftMax=max(leftMax,height[l]);
                l++;
            }
            else{
                if(height[r]<rightMax) total+=rightMax-height[r];
                rightMax=max(rightMax,height[r]);
                r--;
            }
        }
        return total;
    }
};