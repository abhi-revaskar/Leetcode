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
    unordered_set<int> s;
    void solve(TreeNode* root,int level,vector<int> &ans)
    {
        if(!root)
            return;
        if(s.count(level)==0)
        {
            ans.push_back(root->val);
            s.insert(level);
        }
        if(root->right)
            solve(root->right,level+1,ans);
        if(root->left)
            solve(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        solve(root,0,ans);
        return ans;
    }
};