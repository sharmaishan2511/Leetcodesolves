class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int x = s1.size();
        int y = s2.size();
        vector<int> prev(y+1,0),curr(y+1,0);

        for(int j = 0;j<=y;j++){
            prev[j] = 0;
        }
        
        for(int i = 1;i<=x;i++){
            for(int j = 1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{ 
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        
        return prev[y];
    }
};