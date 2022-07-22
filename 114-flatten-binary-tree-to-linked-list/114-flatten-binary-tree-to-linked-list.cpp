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
        if(!root)
            return;
        TreeNode* temp = root;
        while(temp)
        {
            if(!temp->left)
                temp=temp->right;
            else
            {
                TreeNode* pred=temp->left;
                while(pred->right)
                    pred=pred->right;
                pred->right = temp->right;
                temp->right = temp->left;
                temp->left = NULL;
            }
        }
    }
};