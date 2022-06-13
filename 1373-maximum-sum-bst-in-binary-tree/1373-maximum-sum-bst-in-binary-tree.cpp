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
    int ans=0;
    vector<int> BstAndSum(TreeNode* root)
    {
        if(!root)
            return {INT_MAX,INT_MIN,0};
        auto t1 = BstAndSum(root->left);
        auto t2 = BstAndSum(root->right);
        if(root->val > t1[1] && root->val < t2[0])
        {
            ans=max(ans,root->val+t1[2]+t2[2]);
            return {min(t1[0],root->val),max(t2[1],root->val),root->val+t1[2]+t2[2]};
        }
        return {INT_MIN,INT_MAX,root->val+t1[2]+t2[2]};
    }
    int maxSumBST(TreeNode* root) {
        BstAndSum(root);
        return ans;
    }
};