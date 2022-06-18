class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int> &nums,int i,int s1,int s2)
    {
        if(dp[i][s1]!=-1)
            return dp[i][s1];
        if(i==nums.size())
            return s1==s2;
        return dp[i][s1] = solve(nums,i+1,s1+nums[i],s2) || solve(nums,i+1,s1,s2+nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        // int s1=0,s2=0;
        // memset(dp,-1,sizeof(dp));
        // return solve(nums,0,s1,s2);
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        if(sum&1)
            return 0;
        vector<bool> dp(sum/2+1,0),prev(sum/2+1,0);
        prev[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j = 1 ;j<=sum/2;j++)
            {
                if(nums[i]<=j)
                    dp[j]=prev[j]||prev[j-nums[i]];
            }
            prev=dp;
        }
        return prev.back();
    }
};