class Solution {
public:
    void solve(int i,vector<int> &ds,vector<vector<int>> &ans,int t,vector<int> &nums)
    {
        if(t==0)
        {
            ans.push_back(ds);
            return;
        }
        if(t<0 || i==nums.size())
            return;
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1])
                continue;
            ds.push_back(nums[j]);
            solve(j+1,ds,ans,t-nums[j],nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(cand.begin(),cand.end());
        solve(0,ds,ans,target,cand);
        return ans;
    }
};