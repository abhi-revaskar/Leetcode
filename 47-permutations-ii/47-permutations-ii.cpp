class Solution {
public:
    void find(int i,vector<int> nums,vector<vector<int>> &ans)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(i!=j && nums[i]==nums[j])
                continue;
            {
                swap(nums[i],nums[j]);
                find(i+1,nums,ans);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        find(0,nums,ans);
        return ans;
    }
};