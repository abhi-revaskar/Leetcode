class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &t1,string &t2)
    {
        if(i==t1.length() || j==t2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(t1[i]==t2[j])
            return dp[i][j] = 1+solve(i+1,j+1,t1,t2);
        return dp[i][j] = max(solve(i,j+1,t1,t2),solve(i+1,j,t1,t2));
    }
    int longestCommonSubsequence(string t1, string t2) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,t1,t2);
        int n = t1.length(),m = t2.length();
        vector<int> dp(m+1,0),prev(m+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[0] = 0;
            for(int j=1;j<=m;j++)
            {
                if(t1[i-1]==t2[j-1])
                    dp[j] = 1 + prev[j-1];
                else
                    dp[j] = max(dp[j-1],prev[j]);
            }
            prev = dp;
        }
        return prev.back();
    }
};