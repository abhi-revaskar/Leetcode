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
    string tree2str(TreeNode* root) {
        string left;
        if(root->left)
            left = tree2str(root->left);
        string right;
        if(root->right)
            right = tree2str(root->right);
        string ans = to_string(root->val);
        if(left=="" && right=="")
            return ans;
        if(right!="")
            return ans+'('+left+')'+'('+right+')';
        return ans+'('+left+')';
    }
};