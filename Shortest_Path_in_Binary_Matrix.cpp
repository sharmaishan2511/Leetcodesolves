class Solution {
public:
    vector<int> vx = {1,1,0,-1,0,-1,1,-1};
    vector<int> vy = {1,0,1,-1,-1,0,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if(n==0) return -1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;

            if(x==n-1 && y==n-1){
                return grid[x][y];
            }

            for(int i = 0;i<8;i++){
                int xn = x+vx[i];
                int yn = y+vy[i];
                if(xn>=0 && xn<n && yn>=0 && yn<n && grid[xn][yn]==0){
                    q.push({xn,yn});
                    grid[xn][yn]=1+grid[x][y];
                }
            }

        }
        return -1;
    }
};