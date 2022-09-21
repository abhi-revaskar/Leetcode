class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumb4=0,n = nums.size();
        vector<int> ans;
        for(auto &x:nums)
            if(x%2==0)
                sumb4+=x;
        for(auto &x:queries)
        {
            if(nums[x[1]]%2==0)
                sumb4-=nums[x[1]];
            nums[x[1]]+=x[0];
            if(nums[x[1]]%2==0)
            {
                sumb4+=nums[x[1]];
            }
            
            ans.push_back(sumb4);
        }
        return ans;
    }
};