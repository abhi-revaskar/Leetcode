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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size=q.size();
            while(size--)
            {
                auto frontnode = q.front();
                q.pop();
                level.push_back(frontnode->val);
                if(frontnode->left)
                    q.push(frontnode->left);
                if(frontnode->right)
                    q.push(frontnode->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};