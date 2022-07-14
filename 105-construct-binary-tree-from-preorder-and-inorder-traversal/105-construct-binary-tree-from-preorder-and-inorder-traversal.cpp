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
    int idx=0;
    unordered_map<int,int> mp;
    TreeNode* solve(int l,int r,vector<int> &preorder)
    {
        if(l>r)
            return NULL;
        int val = preorder[idx];
        TreeNode *node = new TreeNode(val);
        idx++;
        node->left = solve(l,mp[val]-1,preorder);
        node->right= solve(mp[val]+1,r,preorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(0,preorder.size()-1,preorder);
    }
};