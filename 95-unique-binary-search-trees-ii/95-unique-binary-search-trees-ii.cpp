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
    vector<TreeNode*> solve(int i,int j,vector<int> &nums)
    {
        if(i>j)
            return {NULL};
        if(i==j)
            return {new TreeNode(nums[i])};
        vector<TreeNode*> ans;
        for(int k=i;k<=j;k++)
        {
            auto left = solve(i,k-1,nums);
            auto right = solve(k+1,j,nums);
            for(auto leftchild:left)
            {
                for(auto rightchild:right)
                {
                    TreeNode* node = new TreeNode(nums[k]);
                    node->left = leftchild;
                    node->right = rightchild;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        return solve(0,n-1,nums);
    }
};