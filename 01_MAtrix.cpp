class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //return mat;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==1){
                    int top,left;
                    if(i-1<0){
                        top = 1e9;
                    }else{
                        top = mat[i-1][j];
                    }
                    if(j-1<0){
                        left = 1e9;
                    }else{
                        left = mat[i][j-1];
                    }
                    mat[i][j]=min(top,left)+1;
                }else{
                    mat[i][j] = 0;
                }
            }
        }

        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                int bottom,right;
                if(i+1>=m){
                    bottom = 1e9;
                }else{
                    bottom = mat[i+1][j];
                }
                if(j+1>=n){
                    right = 1e9;
                }else{
                    right = mat[i][j+1];
                }
                mat[i][j]=min(mat[i][j],min(bottom,right)+1);
                
            }
        }

        return mat;
    }
};