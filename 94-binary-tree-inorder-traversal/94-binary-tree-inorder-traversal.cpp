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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        TreeNode *t = root;
        stack<TreeNode*> st;
        while(true)
        {
            while(t)
            {
                st.push(t);
                t = t->left;
            }
            if(st.empty())
                return ans;
            t = st.top();
            ans.push_back(t->val);
            st.pop();
            t = t->right;
        }
        return ans;
    }
};