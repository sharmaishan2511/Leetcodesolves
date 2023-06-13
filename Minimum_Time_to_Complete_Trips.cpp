class Solution {
public:
    long long int f(vector<int> &time,long long int mid){
        long long int ans = 0;

        for(int i = 0;i<time.size();i++){
            ans += (mid/time[i]);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        /*if(time.size()==1){
            return time[0];
        }*/

        long long int lo = 1;
        long long int hi = 1e14;

        while(lo<hi){
            long long int mid =lo+ (hi-lo)/2;

            if(f(time,mid)>=totalTrips){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        return lo;
    }
};