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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        int turn = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int t = q.size(),i=0;
            if(turn)
                i=t-1;
            vector<int> level(t);
            while(t--)
            {
                auto top = q.front();
                q.pop();
                level[i]=top->val;
                if(turn)
                    i--;
                else 
                    i++;
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            turn =1-turn;
            ans.push_back(level);
        }
        return ans;
    }
};