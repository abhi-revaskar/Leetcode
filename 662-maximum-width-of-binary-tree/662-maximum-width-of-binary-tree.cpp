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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            long long min=q.front().second;
            long long curr = q.size();
            while(curr--)
            {
                auto t=q.front();
                ans=max(ans,t.second-min+1);
                q.pop();
                if(t.first->left)
                q.push({t.first->left,2*(t.second-min)+1});
                if(t.first->right)
                q.push({t.first->right,2*(t.second-min)+2});                
            }
        }
        return ans;
    }
};