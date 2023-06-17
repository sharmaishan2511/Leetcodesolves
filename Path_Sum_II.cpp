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
    void f(TreeNode* root,int k,int curr,vector<vector<int>> &ans,vector<int> &v){
        if(!root){
            return;
        }
        v.push_back(root->val);
        if(!root->left && !root->right){
            if(k==curr+root->val){
                ans.push_back(v);
            }
        }else{
            f(root->left,k,curr+root->val,ans,v);
            f(root->right,k,curr+root->val,ans,v);
        }
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        if(!root){
            return ans;
        }
        //v.push_back(root->val);
        f(root,targetSum,0,ans,v);
        return ans;
    }
};