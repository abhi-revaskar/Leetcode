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
    bool find(TreeNode* root)
    {
        if(!root)
            return 0;
        auto left = find(root->left);
        auto right = find(root->right);
        if(!left)
            root->left = NULL;
        if(!right)
            root->right = NULL;
        return left || right || root->val==1;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!find(root))
            return NULL;
        return root;
    }
};