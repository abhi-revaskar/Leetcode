class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i>j)
            return dp[i][j] = 0;        
        if(i==j)
            return dp[i][j] =  1;
        if(s[i]==s[j])
            return dp[i][j]=solve(i+1,j-1,s)+2;
        return dp[i][j]=max(solve(i+1,j,s),solve(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s.length(),s);
        
    }
};