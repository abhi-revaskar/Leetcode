class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string &s)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i>=j)
            return dp[i][j] = 0;
        if(s[i]==s[j])
            return dp[i][j] = solve(i+1,j-1,s);
        return dp[i][j] = min(solve(i,j-1,s),solve(i+1,j,s))+1;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s.length()-1,s);
    }
};