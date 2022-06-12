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
    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
        if(idx>=A.size() || A[idx]>bound)
            return NULL;
        TreeNode* node = new TreeNode(A[idx++]);
        node ->left = bstFromPreorder(A,node->val);
        node ->right = bstFromPreorder(A,bound);
        return node;
        
    }
};