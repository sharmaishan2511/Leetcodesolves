class Solution {
public:
    /*int f(int ind,int buy,vector<int>& prices,int n,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        int profit = 0;
        
        if(buy){
            int t = -prices[ind]+f(ind+1,0,prices,n,dp);
            int nt = f(ind+1,1,prices,n,dp);
            profit = max(t,nt);
        }else{
            int t = prices[ind]+f(ind+1,1,prices,n,dp);
            int nt = f(ind+1,0,prices,n,dp);
            profit = max(t,nt);
        }
        return dp[ind][buy]=profit;
    }*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        vector<int> ahead(2,-1),curr(2,-1);
        
        ahead[0]=ahead[1]=0;
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
        
                if(buy){
                    int t = -prices[ind]+ahead[0];
                    int nt = ahead[1];
                    profit = max(t,nt);
                }else{
                    int t = prices[ind]+ahead[1];
                    int nt = ahead[0];
                    profit = max(t,nt);
                }
                curr[buy]=profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};