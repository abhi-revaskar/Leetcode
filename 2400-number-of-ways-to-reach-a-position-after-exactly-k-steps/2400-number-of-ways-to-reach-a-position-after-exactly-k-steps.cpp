class Solution {
    int mod = 1e9+7;
public:
    long long dp[2001][2001];
    int solve(int diff,int k)
    {
        if(k==0)
        {
            return diff==0;
        }
        if(dp[diff][k]!=-1)
            return dp[diff][k];
        return dp[diff][k] = (solve(abs(diff-1),k-1)%mod+solve(abs(diff+1),k-1)%mod)%mod;
    }
    int numberOfWays(int start, int end, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(abs(start-end),k)%mod;
    }
};