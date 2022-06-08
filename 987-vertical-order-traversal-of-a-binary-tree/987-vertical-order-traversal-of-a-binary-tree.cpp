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
    void solve(TreeNode* root,int vert,int level,map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> &mp)
    {
        if(!root)
            return;
        mp[vert][level].push(root->val);
        solve(root->left,vert-1,level+1,mp);
        solve(root->right,vert+1,level+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> mp;
        solve(root,0,0,mp);
        
        for(auto x:mp)
        {
            vector<int> t;
            for(auto y:x.second)
            {
                while((!y.second.empty()))
                {
                    t.push_back(y.second.top());
                y.second.pop();
                }
                
            }
            ans.push_back(t);
        }
        return ans;
    }
};