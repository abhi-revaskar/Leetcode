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
    unordered_map<int,int> mp;
    int i;
    TreeNode* solve(vector<int> inorder,vector<int> postorder,int l,int r)
    {
        if(l>r)
            return NULL;
        int val = postorder[i];
        i--;
        TreeNode* node=new TreeNode(val);
        node ->right = solve(inorder,postorder,mp[val]+1,r);
        node ->left = solve(inorder,postorder,l,mp[val]-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        i=inorder.size()-1;
        for(int i=0;i<=inorder.size()-1;i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(inorder,postorder,0,i);
    }
};