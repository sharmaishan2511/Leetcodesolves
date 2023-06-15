class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

        for(int i = 0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        dist[k]=0;

        while(!q.empty()){
            int node = q.top().second;
            q.pop();

            for(auto it : adj[node]){
                int adn = it.first;
                int adwt = it.second;

                if(dist[adn]>dist[node]+adwt){
                    dist[adn]=dist[node]+adwt;
                    q.push({dist[adn],adn});
                }
            }
        }

        dist[0]=-1;

        for(int i = 1;i<n+1;i++){
            if(dist[i]==1e9){
                return -1;
            }
        }
        int ans = 0;
        for(int i = 1;i<n+1;i++){
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};