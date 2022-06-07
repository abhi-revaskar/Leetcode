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
    void solve(TreeNode* root,int level,int &cnt,int &ans)
    {
        if(!root)
            return;
        if(level == cnt)
        {
            ans=root->val;
            cnt++;
        }
        solve(root->left,level+1,cnt,ans);
        solve(root->right,level+1,cnt,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int cnt=0;
        int ans;
        solve(root,0,cnt,ans);
        return ans;
    }
};