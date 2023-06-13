class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans = 0;
        long long int z = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }else{
                ans+=(z*(z+1))/2;
                z=0;
            }
        }

        ans+=(z*(z+1))/2;
        return ans;
    }
};