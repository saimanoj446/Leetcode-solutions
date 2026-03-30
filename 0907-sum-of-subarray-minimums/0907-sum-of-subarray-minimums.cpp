class Solution {
public:
    vector<int> getpsee(vector<int>& arr){
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]= -1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getnse(vector<int>& arr){
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]= n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        vector<int> psee=getpsee(arr);
        vector<int> nse=getnse(arr);
        int total=0;
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total = (total+(1LL*right*left*arr[i])%mod)%mod;
        }
        return total;
        
    }
};