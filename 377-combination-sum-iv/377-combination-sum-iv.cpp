class Solution {
public:
    int dp[1001],ans;
    int solve(int t,vector<int> &nums)
    {
        if(t<0)
            return 0;
        if(dp[t]!=-1)
            return dp[t];
        if(t==0)
        {
            return 1;
        }
        int cnt = 0;
        for(int j=0;j<nums.size();j++)
        {
            cnt+=solve(t-nums[j],nums);
        }
        dp[t]=cnt;
        // cout<<t<<" "<<dp[t]<<endl;
        return dp[t];
    }
    int combinationSum4(vector<int>& nums, int t) {
        memset(dp,-1,sizeof(dp));
        // for(int i=0;i<=t;i++)
        //     cout<<dp[i]<<" ";
        return solve(t,nums);
    }
};