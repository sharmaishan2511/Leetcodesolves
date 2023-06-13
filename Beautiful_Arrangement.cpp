class Solution {
public:
    int f(int l,int h,vector<int> &nums){
        if(l==h){
            return 1;
        }
        int sum=0;
        for(int i = l;i<h;i++){
            if(nums[i]%(l+1)==0 || (l+1)%nums[i]==0){
                swap(nums[l],nums[i]);
                sum+=f(l+1,h,nums);
                swap(nums[l],nums[i]);
            }
        }
        return sum;
    }
    int countArrangement(int n) {
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
            arr[i] = i+1;
        }

        return f(0,n,arr);

    }
};