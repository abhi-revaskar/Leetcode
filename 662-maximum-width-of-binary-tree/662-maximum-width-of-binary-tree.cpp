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
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int mini = INT_MAX;
            ans = max(ans,q.back().second-q.front().second+1);
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                if(top.first->left)
                {
                    mini = min(mini,top.second);
                    q.push({top.first->left,(top.second-mini)*2+1});
                }
                if(top.first->right)
                {
                    mini = min(mini,top.second);
                    q.push({top.first->right,(top.second-mini)*2+2});
                }
            }
        }
        return ans;
    }
};