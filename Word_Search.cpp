class Solution {
public:
    bool a = false;
    void dfs(int i,int j,int ind,vector<vector<char>>& board, string word,vector<vector<int>> &vis){
        if(ind==word.size()){
            a=true;
            return;
        }
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 || word[ind]!=board[i][j] || vis[i][j]==1){
            //vis[i][j]=0;
            return;
        }

        vis[i][j]=1;
        dfs(i-1,j,ind+1,board,word,vis);
        dfs(i+1,j,ind+1,board,word,vis);
        dfs(i,j-1,ind+1,board,word,vis);
        dfs(i,j+1,ind+1,board,word,vis);
        vis[i][j]=0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> vis(m,vector<int>(n,0));
                    dfs(i,j,0,board,word,vis);
                }
            }
        }
        return a;
    }
};