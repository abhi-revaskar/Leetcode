class Solution {
public:
    int dp[10001];
    int solve(int i,vector<int> &nums)
    {
        if(i==nums.size()-1)
            return 1;
        if(i>=nums.size())
            return false;
        if(nums[i]==0)
            return false;
        if(dp[i]!=-1)
            return dp[i];
        for(int idx=1;idx<=nums[i];idx++)
            if(solve(idx+i,nums))
                return dp[i] = true;
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};