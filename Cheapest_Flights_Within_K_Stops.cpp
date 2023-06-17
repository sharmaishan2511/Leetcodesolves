class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,pair<int,int>>>> adj(n);
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1],{it[2],0}});
        }
        
        queue<pair<int,pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        
        dist[src] = 0;
        pq.push({0,{src,0}});

        while(!pq.empty()){
            
            auto a = pq.front();
            pq.pop();
            
            int dis = a.first;
            int node = a.second.first;
            int stop =a.second.second;
            
            if(stop>k) continue;
            for(auto it : adj[node]){
                int wt = it.second.first;
                int adjnode = it.first;
                
                if(dis + wt < dist[adjnode]){
                    dist[adjnode] = dis+wt;
                    pq.push({dist[adjnode],{adjnode,stop+1}});
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};