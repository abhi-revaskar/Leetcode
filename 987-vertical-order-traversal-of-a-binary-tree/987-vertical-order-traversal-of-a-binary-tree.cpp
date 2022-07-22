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
    void solve(TreeNode* root,int vert,int level,map<int,map<int,multiset<int>>> &mp)
    {
        if(!root)
            return;
        mp[vert][level].insert(root->val);
        solve(root->left,vert-1,level+1,mp);
        solve(root->right,vert+1,level+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        solve(root,0,0,mp);
        
        for(auto x:mp)
        {
            vector<int> t;
            for(auto y:x.second)
            {
                for(auto val:y.second)
                    t.push_back(val);
                
            }
            ans.push_back(t);
        }
        return ans;
    }
};