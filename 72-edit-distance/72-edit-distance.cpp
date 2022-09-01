class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string &s,string &t)
    {
        if(i==s.length())
            return t.length()-j;
        if(j==t.length())
            return s.length()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = solve(i+1,j+1,s,t);
        return dp[i][j] = 1+min(solve(i+1,j,s,t),min(solve(i+1,j+1,s,t),solve(i,j+1,s,t)));
    }
    int minDistance(string s, string t) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,s,t);
        int n=s.length(),m = t.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=m;i++)
            dp[0][i] = i;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
        return dp.back().back();
    }
};