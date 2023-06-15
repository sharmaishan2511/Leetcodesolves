class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];

        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pair<double,int>> pq;
        //vector<int> vis(n);
        vector<double> probdist(n,-1);

        pq.push({-1,start});
        probdist[start]=1e5;
        double ans = 0;
        while(!pq.empty()){
            int prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node==end){
                ans=prob;
                break;
            }
            //vis[node]=1;

            for(auto it : adj[node]){
                    int adjnode = it.first;
                    double probadj =it.second;
                    
                    if(probdist[adjnode]<probadj*probdist[node]){
                        probdist[adjnode]=probadj*probdist[node];
                        pq.push({probadj*probdist[node],adjnode});
                    }
            }
        }
        return ans*1e-5;
    }
};