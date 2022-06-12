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
    int idx=0;
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int> pre,int l,int r)
    {
        
        if(l>r)
            return NULL;
        int val=pre[idx];
        TreeNode* node = new TreeNode(val);
        idx++;
        TreeNode* le =  solve(pre,l,mp[val]-1);
        TreeNode* ri =  solve(pre,mp[val]+1,r);
        node->left = le;
        node->right = ri;
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> a(preorder);
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            mp[a[i]]=i;
        }
        return solve(preorder,0,a.size()-1);
    }
};