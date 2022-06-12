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
    int kthSmallest(TreeNode* root, int k) {
        int c=1;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            auto t = st.top();
            if(!t)
            {
                st.pop();
                t = st.top();
                if(c==k)
                    return t->val;
                c++;
                st.pop();
                st.push(t->right);
            }
            else
                st.push(t->left);
        }
        return c;
    }
};