class Solution {
public:
    int mini = 1e9;
    void dfs(int i,vector<int> &vis,vector<pair<int,int>> adj[]){

        vis[i]=1;

        for(auto it : adj[i]){
            int v = it.first;
            int wt = it.second;
            mini=min(mini,wt);
            if(!vis[v]){
                dfs(v,vis,adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> vis(n+1,0);
        dfs(1,vis,adj);
        return mini;
    }
};