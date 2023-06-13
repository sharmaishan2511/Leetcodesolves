class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        int i = startPos[0];
        int j = startPos[1];
        
        int m = homePos[0];
        int n = homePos[1];
        
        if(i<m){
            while(i!=m){
                i++;
                ans+=rowCosts[i];
            }
        }else{
            while(i!=m){
                i--;
                ans+=rowCosts[i];
            }
        }
        
        if(j<n){
            while(j!=n){
                j++;
                ans+=colCosts[j];
            }
        }else{
            while(j!=n){
                j--;
                ans+=colCosts[j];
            }
        }
        
        return ans;
        
    }
};