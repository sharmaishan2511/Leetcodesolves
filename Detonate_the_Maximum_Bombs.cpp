class Solution {
public:
    bool isin(int x,int y,int x1,int y1,int r){
        double a = pow((x-x1),2);
        double b = pow((y-y1),2);
        double c = pow(r,2);
        if(a+b-c<=0){
            return true;
        }
        return false;
    }
    
    void dfs(int i,vector<int> &vis,vector<int> adj[],int &ans){
        vis[i]=1;
        ans++;
        for(auto it : adj[i]){
            if(!vis[it]){
                //ans++;
                dfs(it,vis,adj,ans);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        
        //may sort
        for(int i = 0;i<n;i++){
            int x1=bombs[i][0];
            int y1=bombs[i][1];
            int r1=bombs[i][2];

            for(int j = 0;j<n;j++){
                if(i!=j){
                    int x = bombs[j][0];
                    int y = bombs[j][1];

                    if(isin(x,y,x1,y1,r1)){
                        adj[i].push_back(j);
                        //adj[j].push_back(i);
                    }
                }
            }
        }

        //int ans = 1;
        int fans=INT_MIN;
        for(int i = 0;i<n;i++){
            int ans = 0;
            vector<int> vis(n,0);
            dfs(i,vis,adj,ans);
            fans=max(ans,fans);
            
        }
        return fans;
    }
};