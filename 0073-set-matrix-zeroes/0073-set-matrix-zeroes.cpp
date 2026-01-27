class Solution {
public:
    void makerow(int i,vector<vector<int>>& matrix){
        int n=matrix.size();//rows
        int m=matrix[0].size();//columns
        for(int j=0;j<m;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-1e9;
            }
        }
    }
    void makecol(int j,vector<vector<int>>& matrix){
        int n=matrix.size();//rows
        int m=matrix[0].size();//columns
        for(int i=0;i<n;i++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-1e9;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();//rows
        int m=matrix[0].size();//columns
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    makerow(i,matrix);
                    makecol(j,matrix);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1e9){
                    matrix[i][j]=0;
                }
            }
        }

    }
};