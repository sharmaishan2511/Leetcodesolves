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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        
        if(root==NULL){
            return ans;
        }
        
        TreeNode *temp;
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                ans.push_back(v);
                v.clear();
            }else{
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};