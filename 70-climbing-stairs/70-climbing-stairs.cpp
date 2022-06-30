class Solution {
public:
    int dp[46];
    int solve(int n,int i)
    {
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(n==1 || i==n)
            return dp[i]=1;
        return dp[i] = solve(n,i+1) + solve(n,i+2);
    }
    int climbStairs(int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve(n,0);
        if(n==1 || n==2)
            return n;
        vector<int> dp(n+1,0);
        dp[n-1]=1;
        dp[n-2] = 2;
        for(int i=n-3;i>=0;i--)
        {
            dp[i] = dp[i+1]+dp[i+2];
        }
        return dp[0];
    }
};