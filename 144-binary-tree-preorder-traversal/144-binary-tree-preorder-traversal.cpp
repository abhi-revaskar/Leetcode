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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            auto top = st.top();
            ans.push_back(top->val);
            st.pop();
            if(top->right)
                st.push(top->right);
            if(top->left)
                st.push(top->left);
        }
        return ans;
        
    }
};