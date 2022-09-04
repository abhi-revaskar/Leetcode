class Solution {
    int mod = 1e9+7;
public:
    long long dp[1001][1001];
    int solve(int diff,int k)
    {
        if(diff==k)
            return 1;
        if(diff>k)
            return 0;
        if(dp[diff][k]!=-1)
            return dp[diff][k];
        return dp[diff][k] = (solve(abs(diff+1),k-1)%mod+solve(abs(diff-1),k-1)%mod)%mod;
    }
    int numberOfWays(int s, int e, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(abs(s-e),k)%mod;
    }
};