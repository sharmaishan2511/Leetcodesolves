class Solution {
public:
    bool f(int i,int c,string s,vector<vector<int>> &dp){
        if(c<0 || i>s.size()){
            return false;
        }
        
        if(i==s.size()){
            if(c==0){
                return true;
            }else{
                return false;
            }
        }

        if(dp[i][c]!=-1)return dp[i][c];

        if(s[i]=='('){
            return dp[i][c] =f(i+1,c+1,s,dp);
        }else if(s[i]==')'){
            return dp[i][c] =f(i+1,c-1,s,dp);
        }else{
            return dp[i][c] = f(i+1,c+1,s,dp)|f(i+1,c-1,s,dp)|f(i+1,c,s,dp);
        }
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,s,dp);
    }
};