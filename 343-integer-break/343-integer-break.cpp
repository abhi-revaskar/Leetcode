class Solution {
public:
    int dp[59];
    int solve(int n)
    {
        if(dp[n]!=-1)
            return dp[n];
        if(n==1)
            return 1;
        int ans = n;
        for(int i=1;i<n;i++)
        {
            ans = max(ans,i*solve(n-i));
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        if(n==2 || n==3)
            return n-1;
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};