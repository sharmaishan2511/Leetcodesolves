/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long int sum = 0;
    long long int makeno(vector<int> &arr){
        long long int ans = 0;
        long long int n = arr.size();
        long long int k = 1;
        for(long long int i = n-1;i>=0;i--){
            ans+=k*arr[i];
            k=k*10;
        }
        return ans;
    }
    void dfs(TreeNode* root,vector<int> &arr){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            arr.push_back(root->val);
            sum+=makeno(arr);
            arr.pop_back();
            return;
        }
        
        arr.push_back(root->val);
        dfs(root->left,arr);
        arr.pop_back();

        arr.push_back(root->val);
        dfs(root->right,arr);
        arr.pop_back();
        
    }
    int sumNumbers(TreeNode* root) {
        vector<int> arr;
        dfs(root,arr);
        return sum;
    }
};