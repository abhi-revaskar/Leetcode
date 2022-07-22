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
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            long long mini = q.front().second;
            ans = max(ans,q.back().second-mini+1);
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                if(top.first->left)
                    q.push({top.first->left,(top.second-mini)*2+1});
                if(top.first->right)
                    q.push({top.first->right,(top.second-mini)*2+2});
            }
        }
        return ans;
    }
};