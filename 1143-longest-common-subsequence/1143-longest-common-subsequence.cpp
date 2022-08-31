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
        memset(dp,-1,sizeof(dp));
        return solve(0,0,t1,t2);
    }
};