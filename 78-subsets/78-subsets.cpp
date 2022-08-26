class Solution {
public:
    void solve(int i,vector<vector<int>> &ans,vector<int> &subset,vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(subset);
            return;
        }
        // not pick
        solve(i+1,ans,subset,nums);
        //pick
        subset.push_back(nums[i]);
        solve(i+1,ans,subset,nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0,ans,subset,nums);
        return ans;
    }
};