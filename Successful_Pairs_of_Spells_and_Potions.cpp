class Solution {
public:
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        int m = spells.size();
        vector<int> ans(m);
        sort(potions.begin(),potions.end());

        for(int i = 0;i<m;i++){
            int hi = n-1;
            int lo = 0;

            while(lo<=hi){
                int mid=(lo+hi)/2;
                long long mul = (long long int)spells[i]*(long long int)potions[mid];
                if(mul>=success){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            ans[i]=n-hi-1;
        }
        
        return ans;
    }
};