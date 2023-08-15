class Solution {
public:
    int f(vector<int> &arr,int i,int k){
        vector<int> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0] = 1;
        
        if(arr[0]<=k) prev[arr[0]] = 1;
        
        for(int ind = 1;ind<i;ind++){
            for(int target=1;target<=k;target++){
                int nt = prev[target];
                int t = 0;
                if(arr[ind]<=target) t = prev[target-arr[ind]];
                curr[target] = t|nt;
            }
            prev = curr;
        }
        
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int target = 0;
        for(int i = 0;i<N;i++){
            target+=nums[i];
        }
        
        if(target%2!=0) return 0;
        target=target/2;
        
        return f(nums,N-1,target);
    }
};