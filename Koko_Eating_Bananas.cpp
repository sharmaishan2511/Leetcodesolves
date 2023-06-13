class Solution {
public:
    long long int calc(vector<int>& piles,int time){
        long long int v = 0;
        for(int i = 0;i<piles.size();i++){
            if(piles[i]%time==0){
                v+=piles[i]/time;
            }else{
                v+=piles[i]/time+1;
            }
        }
        return v;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1e9;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(calc(piles,mid)<=h){
                hi = mid-1;
            }else if(calc(piles,mid)>h){
                lo = mid+1;
            }
        }
        return lo;

    }
};