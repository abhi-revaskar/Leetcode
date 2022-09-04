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
    map<int,map<int,multiset<int>>> mp;
public:
    void solve(int row,int col,TreeNode* root)
    {
        if(!root)
            return;
        mp[col][row].insert(root->val);
        solve(row+1,col-1,root->left);
        solve(row+1,col+1,root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(0,0,root);
        vector<vector<int>> ans;
        for(auto &col:mp)
        {
            vector<int> colvals;
            for(auto &row:col.second)
            {
                for(auto &x:row.second)
                {
                    colvals.push_back(x);
                }
            }
            ans.push_back(colvals);
        }
        return ans;
    }
};