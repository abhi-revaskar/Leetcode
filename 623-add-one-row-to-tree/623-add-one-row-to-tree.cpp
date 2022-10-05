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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        depth--;
        while(--depth)
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front();q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        while(!q.empty())
        {
            auto n = q.front();q.pop();
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->left = n->left;
            r->right = n->right;
            n->left = l;
            n->right = r;
        }
        return root;
    }
};