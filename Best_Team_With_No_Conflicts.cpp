class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vp;

        int n = scores.size();
        vector<int> take(n,1);
        for(int i = 0;i<n;i++){
            vp.push_back({ages[i],scores[i]});
        }

        sort(vp.begin(),vp.end(),greater<>());

        int ans = 0;
        vector<int> dp(n);

        for(int i = 0;i<n;i++){
            int sum = vp[i].second;
            dp[i]=sum;
            for(int j = 0;j<i;j++){
                if(vp[j].second>=vp[i].second){
                    dp[i]=max(dp[i],dp[j]+vp[i].second);
                }
            }
            ans=max(ans,dp[i]);
        }

        
        return ans;
    }
};