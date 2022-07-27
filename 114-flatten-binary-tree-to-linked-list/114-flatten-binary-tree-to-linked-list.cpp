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
    void flatten(TreeNode* root) {
        while(root)
        {
            if(!root->left)
                root=root->right;
            else
            {
                TreeNode* pred=root->left;
                while(pred->right)
                    pred=pred->right;
                pred->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
        }
    }
};