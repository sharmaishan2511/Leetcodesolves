class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        
        vector<bool> prime(n+1,true);

        for(int p=2;p*p<n;p++){
            if(prime[p]){
                for(int i = p*p;i<n;i+=p){
                    prime[i]=false;
                }
            }
        }

        for(int i = 2;i<n;i++){
            if(prime[i]){
                ans++;
            }
        }
        return ans;
    }
};