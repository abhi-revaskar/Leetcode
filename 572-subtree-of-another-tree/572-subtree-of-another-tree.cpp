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
    bool isSubtree(TreeNode* root, TreeNode* subRoot,int is=1) {
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        if(root->val!=subRoot->val)
        {
            if(is)
            return isSubtree(root->left,subRoot,is) || isSubtree(root->right,subRoot,is);
            else
                return false;            
        }
        int left = isSubtree(root->left,subRoot->left,0);
        int right = isSubtree(root->right,subRoot->right,0);
        int notleft=0,notright=0;
        if(is)
        {
            notleft = isSubtree(root->left,subRoot,is);
            notright = isSubtree(root->right,subRoot,is);  
        } 
        return (left && right) || notleft || notright;
    }
};