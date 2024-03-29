class Solution {
public:
    void solve(int i,vector<int> &nums,vector<vector<int>> &ans)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> s;
        for(int j=i;j<nums.size();j++)
        {
            if(s.count(nums[j]))
                continue;
            swap(nums[i],nums[j]);
            solve(i+1,nums,ans);
            swap(nums[i],nums[j]);
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};