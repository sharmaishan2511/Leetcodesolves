class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        n=n-2;
        
        int tn=0,tn1=1,tn2=1,tn3=1;
        for(int i = 0;i<n;i++){
            tn3=tn+tn1+tn2;
            tn=tn1;
            tn1=tn2;
            tn2=tn3;
        }
        return tn3;
    }
};