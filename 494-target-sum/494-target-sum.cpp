class Solution {
public:
    int dp[21][22001];
    int solve(int i,int t,vector<int> &nums)
    {
        if(i==nums.size())
            return t==1000;      
        if(dp[i][t]!=-1)
            return dp[i][t];
        return dp[i][t] = solve(i+1,t-nums[i],nums)+solve(i+1,t+nums[i],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,target+1000,nums);
    }
};