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
        deque<TreeNode*> q;
        if(!root)
            return ans;
        q.push_back(root);
        int lev=0;
        while(!q.empty())
        {
            vector<int> temp;
            int cur=q.size();
            if(lev%2==0)
            {
                while(cur--)
                {
                    TreeNode* t=q.front();
                    temp.push_back(t->val);
                    q.pop_front();
                    if(t->left)
                        q.push_back(t->left);
                    if(t->right)
                        q.push_back(t->right);
                }
            }
            else
            {
                while(cur--)
                {
                    TreeNode* t=q.back();
                    temp.push_back(t->val);
                    q.pop_back();
                    if(t->right)
                        q.push_front(t->right);
                    if(t->left)
                        q.push_front(t->left);
                    
                }
            }
            ans.push_back(temp);
            lev++;
        }
        return ans;
    }
};