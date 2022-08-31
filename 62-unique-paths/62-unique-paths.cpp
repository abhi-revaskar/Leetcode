class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,int m,int n)
    {
        if(i==m-1 && j==n-1)
            return 1;
        if(min(i,j)<0 || i==m || j==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,m,n);
        vector<int> dp(n,0),prev(n,1);
        for(int i=m-2;i>=0;i--)
        {
            dp[n-1] = 1;
            for(int j=n-2;j>=0;j--)
            {
                dp[j] = dp[j+1]+prev[j];
            }
            prev = dp;
        }
        return prev[0];
    }
};