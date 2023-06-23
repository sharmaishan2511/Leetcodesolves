class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx){
        ans.push_back(curr); 
        for(int i=idx;i<nums.size();i++){
            if(i>idx &&  nums[i]==nums[i-1]) continue; 
            curr.push_back(nums[i]);
            helper(nums,ans,curr,i+1); 
            curr.pop_back(); 
        }
    }  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        //map<vector<int>,int> mp;
        vector<int> v;
        sort(nums.begin(),nums.end());
        helper(nums,ans,v,0);
        return ans;
        
    }
};