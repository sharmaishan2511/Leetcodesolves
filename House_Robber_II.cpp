class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int> &dp){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int pick = nums[ind] + f(ind-2,nums,dp);
        int np = f(ind-1,nums,dp);
        
        return dp[ind] = max(pick,np);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> n1 = nums;
        vector<int> n2 = nums;
        
        n1.pop_back();
        n2.erase(n2.begin());
        
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        
        return max(f(n-2,n1,dp1),f(n-2,n2,dp2));
    }
};