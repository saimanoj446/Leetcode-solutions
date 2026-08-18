class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int  n=position.size();
        vector<pair<int,double>> cars;
        int cnt=0;
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end(),[](const pair<int,double> &a,const pair<int,double> &b){
            return a.first>b.first;
        });
        double maxTime= 0.0;
        for(int i=0;i<n;i++){
            if(cars[i].second>maxTime){
                maxTime=cars[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};