class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int prev2= 0,prev1 = 1,curri;
        
        for(int i = 2;i<=n;i++){
            curri = prev1+prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        
        return prev1;
    }
};