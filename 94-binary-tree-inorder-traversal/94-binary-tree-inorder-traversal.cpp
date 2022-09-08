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
    vector<int> ans;
public:
    void solve(TreeNode* root)
    {
        if(root->left)
            solve(root->left);
        ans.push_back(root->val);
        if(root->right)
            solve(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return ans;
        // solve(root);
        // return ans;
        TreeNode* t = root;
        stack<TreeNode*> st;
        while(true)
        {
            while(t)
            {
                st.push(t);
                t = t->left;
            }
            if(st.empty())
                break;
            t = st.top();st.pop();
            ans.push_back(t->val);
            t = t->right;
        }
        return ans;
    }
};