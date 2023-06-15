class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        vector<vector<int>> dp(n,vector<int>(n,1e9));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==0 && j==0){
                    if(grid[i][j]==0){
                        continue;
                    }
                }
                if(grid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }

                if(i==0){
                    if(dp[i][j-1]>=0)
                        dp[i][j]=1+dp[i][j-1];
                    continue;
                }
                if(j==0){
                    if(dp[i-1][j]>=0)
                        dp[i][j]=1+dp[i-1][j];
                    continue;
                }

                dp[i][j] = min(1+dp[i-1][j],min(1+dp[i][j-1],2+dp[i-1][j-1]));
                
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i==n-1 && j==n-1){
                    continue;
                }
                if(i==n-1){
                    //if(dp[i][j+1]>=0)
                        dp[i][j] = min(dp[i][j],1+dp[i][j+1]);
                    continue;
                }

                if(j==n-1){
                    //if(dp[i+1][j]>=0)
                        dp[i][j] = min(dp[i][j],1+dp[i+1][j]);
                    continue;
                }

                int a = min(1+dp[i+1][j],min(1+dp[i][j+1],2+dp[i+1][j+1]));
                dp[i][j] = min(dp[i][j],a);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                ans= max(ans,dp[i][j]);
            }
        }
        if(ans>=1e9 || ans==0)
            return -1;
        
        return ans;
    }
};