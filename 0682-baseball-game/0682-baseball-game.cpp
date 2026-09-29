class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();
        vector<int>st;
        for(int i=0;i<n;i++){
            if(operations[i]!="C" && operations[i]!="D"&& operations[i]!="+"){
                int x=stoi(operations[i]);
                st.push_back(x);
            }
            else if(operations[i]=="+"){
                int n = st.size();
                int sum = st[n-1] + st[n-2];
                st.push_back(sum);
            }
            else if(operations[i]=="D"){
                st.push_back(2 * st.back());
            }
            else if(operations[i]=="C"){
                if(st.empty()) continue;
                st.pop_back();
            }
        }
        int total = 0;

        for(int i = 0; i < st.size(); i++) {
            total += st[i];
        }

        return total;
    }
};