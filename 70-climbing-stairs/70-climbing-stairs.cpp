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
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};