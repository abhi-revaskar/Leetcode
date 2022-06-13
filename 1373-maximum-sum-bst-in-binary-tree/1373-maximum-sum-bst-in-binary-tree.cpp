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
    unordered_set<TreeNode*> s;
    unordered_map<TreeNode*,int> mp;
    int sum(TreeNode* root)
    {
        if(!root)
            return 0;
        mp[root]=root->val + sum(root->left)+sum(root->right);
        return mp[root];
    }
    pair<int,int> bst(TreeNode* root)
    {
        if(!root)
            return {INT_MAX,INT_MIN};
        auto t1 = bst(root->left);
        auto t2 = bst(root->right);
        if(root->val > t1.second && root->val < t2.first)
        {
            s.insert(root);
            // cout<<root->val<<endl;
            pair<int,int> ans;
            ans.first = min(t1.first,root->val);
            ans.second = max(t2.second,root->val);
            return ans;
        }
        return {INT_MIN,INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        bst(root);
        int ans = 0;
        sum(root);
        for(auto x:s)
        {
            ans=max(ans,mp[x]);
        }
        return ans;
    }
};