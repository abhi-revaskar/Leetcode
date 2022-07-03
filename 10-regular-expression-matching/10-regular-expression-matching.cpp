class Solution {
public:
    int dp[21][31];
    bool solve(int i,int j,string s,string p)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==s.length() && j==p.length())
            return dp[i][j] = true;
        if(i!=s.length() && j==p.length())
            return dp[i][j] = false;
        if(i==s.length())
        {
            if(p[j]=='*')
                return dp[i][j] = solve(i,j+1,s,p);
            if(j==p.length()-1)
                return dp[i][j] = false;
            if(p[j+1]!='*')
                return dp[i][j] = false;
            return dp[i][j] = solve(i,j+1,s,p);
        }
        if(p[j]=='*')
        {
            if(p[j-1]=='.' || p[j-1]==s[i])
                return dp[i][j] = (solve(i+1,j,s,p) || solve(i,j+1,s,p));
            return dp[i][j]= solve(i,j+1,s,p);
        }
        if(j<p.length()-1 && p[j+1]=='*')
            return dp[i][j] = solve(i,j+1,s,p);
        if(p[j]=='.' || p[j]==s[i])
        {
            return dp[i][j] = solve(i+1,j+1,s,p);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p);
    }
};