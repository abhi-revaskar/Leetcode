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
    pair<TreeNode*,TreeNode*> solve(TreeNode* root)
    {
        if(!root->left && !root->right)
            return {root,root};
        if(!root->left)
        {
            pair<TreeNode*,TreeNode*> t= solve(root->right);
            root->right = t.first;
            return {root,t.second};
        }
        if(!root->right)
        {
            auto t= solve(root->left);
            root->right = t.first;
            root->left = NULL;
            return {root, t.second};
        }
        auto t1 = solve(root->left);
        auto t2 = solve(root->right);
        root->right = t1.first;
        t1.second->right = t2.first;
        root->left = NULL;
        return {root, t2.second};
    }
    void flatten(TreeNode* root) {
        if(!root)
            return;
        solve(root);
    }
};