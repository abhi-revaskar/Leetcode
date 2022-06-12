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
class BSTIterator {
public:
    TreeNode* it;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        it=root;
        while(it)
        {
            st.push(it);
            it=it->left;
        }
    }
    
    int next() {
        it=st.top();
        int val=it->val;
        st.pop();
        it=it->right;
        while(it)
        {
            st.push(it);
            it=it->left;
        }
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */