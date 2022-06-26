class Solution {
public:
    void solve(int i,vector<int> &ds,vector<vector<int>> &ans,vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(ds);
            return ;
        }
        solve(i+1,ds,ans,nums); // not pick
        ds.push_back(nums[i]);
        solve(i+1,ds,ans,nums); // pick
        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,ds,ans,nums);
        return ans;
    }
};