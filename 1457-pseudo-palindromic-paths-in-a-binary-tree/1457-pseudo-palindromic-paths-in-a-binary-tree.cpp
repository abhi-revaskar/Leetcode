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
    int solve(TreeNode* root,unordered_map<int,int> &mp)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
        {
            mp[root->val]++;
            int cnt = 0;
            for(auto x:mp)
            {
                 if(x.second&1)
                    cnt++;
            }
            mp[root->val]--;
            return cnt==0 || cnt==1;
        }
        int ans = 0;
        mp[root->val]++;
        ans+=solve(root->left,mp);
        ans+=solve(root->right,mp);
        mp[root->val]--;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        return solve(root,mp);
    }
};