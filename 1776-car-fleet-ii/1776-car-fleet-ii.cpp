class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        stack<int>st;
        int n=cars.size();
        vector<double> ans(n, -1.0);
        for(int i=n-1;i>=0;i--){
            int pos_i = cars[i][0];
            int speed_i = cars[i][1];
            while(!st.empty()){
                int j=st.top();
                int pos_j=cars[j][0];
                int speed_j=cars[j][1];

                if(speed_i<=speed_j){
                    st.pop();
                    continue;
                }
                double t=(double)(pos_j-pos_i)/(speed_i-speed_j);
                if(ans[j]>0 && t>ans[j]){
                    st.pop();
                }
                else{
                    ans[i]=t;
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
};