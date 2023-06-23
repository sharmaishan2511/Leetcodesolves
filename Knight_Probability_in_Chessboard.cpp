class Solution {
public:
    vector<int> dx = {-2,-1,1,2,2,1,-1,-2};
    vector<int> dy = {1,2,2,1,-1,-2,-2,-1};

    bool onboard(int i,int j,int n){
        if(i>=0 && j>=0 && i<n && j<n){
            return true;
        }
        return false;
    }

    double f(int n,int k,int i,int j,vector<vector<vector<double>>> &dp){
        if(!onboard(i,j,n)){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        double a = 0;
        for(int it = 0;it<8;it++){
            int x = i+dx[it];
            int y = j+dy[it];
            a=a+0.125*f(n,k-1,x,y,dp);
            
        }

        return dp[i][j][k]=a;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return f(n,k,row,column,dp);
    }
};