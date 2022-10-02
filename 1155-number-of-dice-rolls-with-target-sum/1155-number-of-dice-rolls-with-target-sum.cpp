class Solution {
    int mod = 1e9+7;
public:
    int dp[32][10001];
    int solve(int i,int sum,int k,int n)
    {
        if(i==n+1)
        {
            return sum==0;
        }
        if(sum<0)
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        long long ans = 0;
        for(int j=1;j<=k;j++)
            ans=(ans+solve(i+1,sum-j,k,n))%mod;
        // cout<<i<<" "<<sum<<" "<<ans<<endl;
        return dp[i][sum] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(1,target,k,n)%mod;
    }
};