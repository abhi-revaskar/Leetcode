class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s,string &t)
    {
        if(j==t.length())
            return 1;
        if(i==s.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]!=t[j])
            return dp[i][j] = solve(i+1,j,s,t);
        return dp[i][j] = solve(i+1,j,s,t)+solve(i+1,j+1,s,t);
    }
    int numDistinct(string s, string t) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,s,t);
        int m = t.length(), n = s.length();
        vector<vector<unsigned>> dp(m + 1, vector<unsigned> (n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
        return dp[m][n];
    }
};