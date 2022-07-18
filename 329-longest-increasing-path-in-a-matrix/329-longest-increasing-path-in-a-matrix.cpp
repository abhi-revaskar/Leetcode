class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>> &matrix)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0,val = matrix[i][j];
        if(i>0 && matrix[i-1][j]>val)
            ans = max(ans,solve(i-1,j,matrix));
        if(j>0 && matrix[i][j-1]>val)
            ans = max(ans,solve(i,j-1,matrix));
        if(i<matrix.size()-1 && matrix[i+1][j]>val)
            ans = max(ans,solve(i+1,j,matrix));
        if(j<matrix[0].size()-1 && matrix[i][j+1]>val)
            ans = max(ans,solve(i,j+1,matrix));
        return dp[i][j] = ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans;
    }
};