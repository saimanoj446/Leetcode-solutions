class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> ans=image;
        queue<pair<pair<int,int>,int>> q;
        if(image[sr][sc]==color) return ans;
        ans[sr][sc]=color;
        q.push({{sr,sc},color});
        while(!q.empty()){
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int colo=it.second;
            int startColor=image[sr][sc];
            q.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int r=row+delRow[i];
                int c=col+delCol[i];
                if(r>=0&&c>=0&&r<m&&c<n&& ans[r][c]==startColor){
                    ans[r][c]=color;
                    q.push({{r,c},color});
                }
            }
        }
        return ans;
    }
};