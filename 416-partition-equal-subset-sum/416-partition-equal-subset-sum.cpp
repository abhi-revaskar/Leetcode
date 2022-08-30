class Solution {
public:
    int dp[201][10001];
    bool solve(int i,int sum,vector<int> &nums)
    {
        if(sum==0)
            return true;
        if(i==nums.size() || nums[i]>sum)
            return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        return dp[i][sum] = solve(i+1,sum,nums) || solve(i+1,sum-nums[i],nums);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        for(auto x:nums)
            sum+=x;
        if(sum&1)
            return false;
        sort(nums.begin(),nums.end());
        return solve(0,sum/2,nums);
    }
};