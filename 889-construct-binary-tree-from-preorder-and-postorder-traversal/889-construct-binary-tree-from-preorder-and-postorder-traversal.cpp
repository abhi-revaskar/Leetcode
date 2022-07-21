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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,TreeNode*> node;
        for(auto x:preorder)
            node[x] = new TreeNode(x);
        unordered_map<int,int> added;
        unordered_map<int,int> idx;
        for(int i=0;i<postorder.size();i++)
            idx[postorder[i]]=i;
        for(int i=0;i<preorder.size();i++)
        {
            if(i<preorder.size()-1)
            {
                TreeNode* left = added[preorder[i+1]]?NULL:node[preorder[i+1]];
                node[preorder[i]]->left = left;                
                if(left)
                added[left->val]=1;
            }
            if(idx[preorder[i]]>0)
            {
                int rightidx = idx[preorder[i]]-1;
                TreeNode* right = NULL;
                if(!added[postorder[rightidx]])
                    right = node[postorder[rightidx]];
                node[preorder[i]]->right = right;
                if(right)
                    added[right->val]=1;
            }
        }
        // for(auto x:preorder)
        // {
        //     cout<<"node:"<<x<<" ";
        //     if(node[x]->left)
        //         cout<<"left:"<<node[x]->left->val;
        //     if(node[x]->right)
        //         cout<<"right:"<<node[x]->right->val;
        //     cout<<endl;
        // }
        return node[preorder[0]];
    }
};