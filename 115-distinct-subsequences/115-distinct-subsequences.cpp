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
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
        // vector<vector<int>> dp(s.length()+1,vector<int> (t.length()+1,0));
        // dp[0][0]=1;
        // for(int i=1;i<=s.length();i++)
        // {
        //     dp[i][0]=1;
        //     for(int j=1;j<=t.length();j++)
        //     {
        //         if(s[i-1]==t[j-1])
        //             dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
        //         else
        //             dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp.back().back();
    }
};