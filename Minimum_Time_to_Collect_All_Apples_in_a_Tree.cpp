class Solution {
public:
    //int ans=0;
    int dfs(int node,int prev,vector<int> adj[],vector<bool>& hasApple){
        int ans = 0;
        for(auto it : adj[node]){
            if(it!=prev){
                int time=dfs(it,node,adj,hasApple);
                if(time>0 || hasApple[it]){
                    ans=ans+time+2;
                }
            }
        }
        return ans;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return dfs(0,-1,adj,hasApple);
        //return ans;
    }
};