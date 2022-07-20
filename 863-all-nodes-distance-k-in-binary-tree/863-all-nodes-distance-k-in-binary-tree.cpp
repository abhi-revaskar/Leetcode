/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,vector<TreeNode*>> adj;
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            dfs(root->left);
        }
        if(root->right)
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        if(adj.size()==0)
        {
            if(k==0)
                return {root->val};
            return {};
        }
        queue<TreeNode*> q;
        vector<int> vis(adj.size(),0);
        vector<int> ans;
        q.push(target);
        vis[target->val]=1;
        int dist = 0;
        while(!q.empty())
        {
            int t = q.size();
            while(t--)
            {
                auto top = q.front();
                q.pop();
                if(dist==k)
                    ans.push_back(top->val);
                for(auto nbr:adj[top])
                    if(!vis[nbr->val])
                    {
                        q.push(nbr);
                        vis[nbr->val]=1;
                    }
            }
            dist++;
        }
        return ans;
    }
};