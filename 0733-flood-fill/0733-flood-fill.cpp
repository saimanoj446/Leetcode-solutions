class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();//rows
        int n=image[0].size();//cols
        queue<pair<pair<int, int>, int>> q;//{{row,col},color}
        vector<vector<int>>ans=image;
        ans[sr][sc]=color;
        int startColor=image[sr][sc];
        if(startColor == color) return image;
        q.push({{sr,sc},color});
        //BFS:
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int col= q.front().second;
            q.pop();
            //check neighbours
            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) {
                int nrow = r + dRow[i];
                int ncol = c + dCol[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && ans[nrow][ncol]==startColor){
                    ans[nrow][ncol]=color;
                    q.push({{nrow,ncol},color});
                }
            }
        }
        return ans;
    }
};