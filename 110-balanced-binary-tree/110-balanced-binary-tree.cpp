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
    int height(TreeNode* root,bool &ans)
    {
        if(!root || !ans)
            return 0;
        int l=height(root->left,ans)+1;
        int r=height(root->right,ans)+1;
        if(abs(l-r)>1)
            ans=false;
        return max(l,r);
        
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        height(root,ans);
        return ans;
    }
};