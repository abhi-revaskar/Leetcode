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
    TreeNode* solve(vector<int> &nums,int i,int j)
    {
        if(i>j)
            return NULL;
        if(i==j)
            return new TreeNode(nums[i]);
        int mid = (i+j)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = solve(nums,i,mid-1);
        TreeNode* right = solve(nums,mid+1,j);
        root->left= left;
        root->right = right;
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};