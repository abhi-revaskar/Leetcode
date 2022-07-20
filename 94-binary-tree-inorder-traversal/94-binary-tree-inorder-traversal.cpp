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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        TreeNode *t = root;
        while(t)
        {
            if(!t->left)
            {
                ans.push_back(t->val);
                t = t->right;
            }
            else
            {
                TreeNode* pred = t->left ;
                while(pred->right)
                {
                    pred = pred->right;
                }
                pred ->right = t;
                pred = t->left;
                t->left=NULL;
                t = pred;
            }
        }
        return ans;
    }
};