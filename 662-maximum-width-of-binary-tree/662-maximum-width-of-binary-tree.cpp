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
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while(!q.empty())
        {
            int mini = INT_MAX;
            ans = max(ans,q.back()->val-q.front()->val+1);
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                if(top->left)
                {
                    mini = min(mini,top->val);
                    top->left->val = (top->val-mini)*2+1;
                    q.push(top->left);
                }
                if(top->right)
                {
                    mini = min(mini,top->val);
                    top->right->val = (top->val-mini)*2+2;
                    q.push(top->right);
                }
            }
        }
        return ans;
    }
};