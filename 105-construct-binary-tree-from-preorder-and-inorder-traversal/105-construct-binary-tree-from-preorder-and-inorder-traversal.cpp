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
    int i=0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int value=preorder[i];
        TreeNode* node= new TreeNode(value);
        i++;
        TreeNode* le=solve(preorder,inorder,l,mp[value]-1);
        node->left=le;
        TreeNode* ri=solve(preorder,inorder,mp[value]+1,r);
        node->right=ri;
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,n-1);
    }
};