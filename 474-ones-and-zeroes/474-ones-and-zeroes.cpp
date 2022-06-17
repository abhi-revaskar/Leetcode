class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>& strs,vector<int> &z, int m, int n,int i)
    {
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        if(i == strs.size())
            return 0;
        int ones = strs[i].length()-z[i];
        int zeros = z[i];
        if(zeros > m || ones > n)
            return dp[i][m][n] = solve(strs,z,m,n,i+1);
        return dp[i][m][n] = max(solve(strs,z,m,n,i+1),1+solve(strs,z,m-zeros,n-ones,i+1));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> z(strs.size(),0);
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i<strs.size();i++)
        {
            for(auto x:strs[i])
            {
                if(x=='0')
                    z[i]++;
            }
        }
        return solve(strs,z,m,n,0);
    }
};