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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(!root)
            return ans;
        int toggle = 1;

        while(!q.empty()){
            int qs = q.size();
            vector<int> v;
            while(qs!=0){
                TreeNode* node = q.front();
                v.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }

                //v.push_back(node->val);
                qs--;
                q.pop();
            }
            if(toggle == 0){
                reverse(v.begin(),v.end());
            }
            toggle = 1-toggle;
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};