class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> costs(n,1e9),vis(n,0);
        vector<pair<int,int>> adj[n];
        for(int i = 0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];

            for(int j = i+1;j<n;j++){
                int x1=points[j][0];
                int y1=points[j][1];
                int dist = abs(x-x1)+abs(y-y1);
                if(i!=j){
                    adj[i].push_back({j,dist});
                    adj[j].push_back({i,dist});
                }
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        costs[0]=0;

        while(!q.empty()){
            int no = q.top().second;
            q.pop();
            if(vis[no]==1){
                continue;
            }

            vis[no]=1;
            for(auto it : adj[no]){
                int w = it.second;
                int v = it.first;

                if(vis[v]==0 && costs[v]>w){
                    costs[v]=w;
                    q.push({w,v});
                }
            }
        }
        /*for(int i = 0;i<n;i++){
            if(costs[i]==1e9){
                costs[i]==0;
            }
        }*/

        int ans = 0;
        for(int i = 0;i<n;i++){
            ans+=costs[i];
        }
        return ans;
    }
};