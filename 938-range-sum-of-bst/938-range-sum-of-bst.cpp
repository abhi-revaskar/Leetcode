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
    bool valid(int m,int low,int high)
    {
        return low<= m && m<=high;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> st;
        int ans = 0;
        st.push(root);
        while(!st.empty())
        {
            auto t = st.top();st.pop();
            if(t && valid(t->val,low,high))
                ans+=t->val;
            if(t)
            {
                if(t->val>low)
                    st.push(t->left);
                if(t->val<high)
                    st.push(t->right);
                    
            }
        }
        return ans;
    }
};