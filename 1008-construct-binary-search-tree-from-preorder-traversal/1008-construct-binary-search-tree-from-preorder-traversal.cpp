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
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int bound = INT_MAX) {
        if(idx>=preorder.size())
            return NULL;
        int val = preorder[idx];
        if(val>bound)
            return NULL;
        TreeNode* node = new TreeNode(val);
        idx++;
        node ->left = bstFromPreorder(preorder,val);
        node ->right = bstFromPreorder(preorder,bound);
        return node;
        
    }
};