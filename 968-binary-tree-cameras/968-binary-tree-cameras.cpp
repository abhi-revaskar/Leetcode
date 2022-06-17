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
    int ans;
    int solve(TreeNode* root)
    {
        if(!root)
            return 2;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l==0 || r==0)
        {
            ans++;
            return 1;
        }
        if(l == 1|| r==1)
            return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        return (solve(root) < 1 ? 1 : 0) + ans;
    }
};