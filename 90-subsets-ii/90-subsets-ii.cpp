class Solution {
public:
    void solve(int i,vector<int> &ds,vector<vector<int>> &ans,vector<int> &nums)
    {
        ans.push_back(ds);
        if(i==nums.size())
            return ;
        for(int idx = i;idx<nums.size();idx++) //subset_size++
        {
            if(idx>i && nums[idx]==nums[idx-1])//already added this no in this call
                continue;
            ds.push_back(nums[idx]);
            solve(idx+1,ds,ans,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(0,ds,ans,nums);
        return ans;
    }
};