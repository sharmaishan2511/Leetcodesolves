class Solution {
public:
    int f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind>=nums.size()-1){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];

        int minj = 1e9;
        for(int i = ind+1;i<=ind+nums[ind];i++){
            minj = min(minj,1+f(i,nums,dp));
        }

        return dp[ind] = minj;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};