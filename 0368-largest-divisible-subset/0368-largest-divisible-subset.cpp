class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (n == 0) return {};
        vector<int> dp(n, 1);
        int maxi = 1;
        int lastIndex = 0;
        vector<int> hash(n);

        for(int i = 0; i < n; i++) {
            hash[i] = i;
        }

        for(int i = 0; i < n; i++) { // Note: changed i=1 to i=0 to be safe, though i=1 works if n>1
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j]==0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j; 
                }    
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis;
        lis.push_back(nums[lastIndex]);
        while(lastIndex != hash[lastIndex]){
            lastIndex = hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};