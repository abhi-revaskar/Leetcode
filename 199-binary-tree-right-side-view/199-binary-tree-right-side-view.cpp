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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
           if(!root)
           return ans;
           queue<TreeNode *> q;
           TreeNode *t=root;
           q.push(t);
           while(!q.empty())
           {
               t=q.front();
               ans.push_back(t->val);
               int cnt=q.size();
               while(cnt--)
               {
                   t=q.front();
                   q.pop();
            
                   if(t->right)
                   q.push(t->right);
                   if(t->left)
                   q.push(t->left);
               }

           }
           return ans;
    }
};