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
 void  solve(TreeNode* &root,int val)
    {
        TreeNode* node = new TreeNode(val);
        if(!root)
        {
            root=node;
            return;
        }
        TreeNode* t = root;
        while(t)
        {
            if(t->val > val)
            {
                if(!t->left)
                {
                    t->left = node;
                    return;
                }
                else 
                    t=t->left;
            }
            else
            {
                if(!t->right)
                {
                    t->right = node;
                    return;
                }
                else 
                    t=t->right;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
       for(int i=0;i<preorder.size();i++) 
       {
           solve(root,preorder[i]);
       }
        return root;
    }
};