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
    long long ans = 0;
    unordered_map<long long,long long> mp;
    void solve(TreeNode* root,int t,long long sum)
    {
        if(!root)
            return;
        sum+=1LL*root->val;
        // cout<<root->val<<" "<<sum<<endl;
        if(mp.count(sum-t))
            ans+=mp[sum-t];
        mp[sum]++;
        solve(root->left,t,sum);
        solve(root->right,t,sum);
        mp[sum]--;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        solve(root,targetSum,0);
        return ans;
    }
};