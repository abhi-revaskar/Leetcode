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
    void solve(TreeNode* root,int vert,int level,int &l,int &r,unordered_map<int,priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>> &mp)
    {
        if(!root)
            return;
        mp[vert].push({level,root->val});
        l=min(l,vert);
        r=max(r,vert);
        solve(root->left,vert-1,level+1,l,r,mp);
        solve(root->right,vert+1,level+1,l,r,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l=0,r=0;
        vector<vector<int>> ans;
        unordered_map<int,priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>> mp;
        solve(root,0,0,l,r,mp);
        ans.resize(r-l+1);
        for(int i=l;i<=r;i++)
        {
            while(!mp[i].empty())
            {
                ans[i-l].push_back(mp[i].top().second);
                mp[i].pop();
            }
        }
        return ans;
    }
};