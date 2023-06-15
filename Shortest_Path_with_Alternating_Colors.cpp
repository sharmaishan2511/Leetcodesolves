class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n];
        vector<vector<int>> color(n,vector<int>(2,-1));

        for(auto it : redEdges){
            adj[it[0]].push_back({it[1],0});
        }

        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1],1});
        }

        queue<pair<int,int>> q;

        color[0]={0,0};
        q.push({0,0});
        q.push({0,1});

        while(!q.empty()){
            int no = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto it : adj[no]){
                int v = it.first;
                int coladj=it.second;
                if(coladj==col || color[v][coladj]!=-1){
                    continue;
                }
                color[v][coladj]=1+color[no][col];
                q.push({v,coladj});
            }
        }
        vector<int> ans;

        for(auto v : color){
            sort(v.begin(),v.end());
            if(v[0]!=-1){
                ans.push_back(v[0]);
            }else{
                ans.push_back(v[1]);
            }
        }
        
        return ans;
    }
};