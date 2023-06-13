class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>,int> mp;
        int n = nums.size();

        vector<int> v;
        int c = 0;

        for(int i = 0;i<n;i++){
            vector<int> v;
            int c = 0;
            for(int j = i;j<n;j++){
                if(nums[j]%p==0){
                    c++;
                }
                if(c>k)
                    break;
                v.push_back(nums[j]);
                mp[v]++;
            }
        }

        return mp.size();
    }
};