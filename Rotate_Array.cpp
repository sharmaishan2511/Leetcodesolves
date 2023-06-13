class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> newa(n);

        for(int i = 0;i<n;i++){
            newa[i]=nums[i];
        }

        for(int i = 0;i<n;i++){
            nums[(i+k)%n]=newa[i];
        }
    }
};