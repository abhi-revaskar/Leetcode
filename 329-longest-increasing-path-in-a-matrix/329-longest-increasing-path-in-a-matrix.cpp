class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0,k = matrix[i][j];
        if(i>0 && matrix[i-1][j]>k)
            ans = max(ans,solve(i-1,j,matrix,dp));
        if(i<matrix.size()-1 && matrix[i+1][j]>k)
            ans = max(ans,solve(i+1,j,matrix,dp));
        if(j>0 && matrix[i][j-1]>k)
            ans = max(ans,solve(i,j-1,matrix,dp));
        if(j<matrix[0].size()-1 && matrix[i][j+1]>k)
            ans = max(ans,solve(i,j+1,matrix,dp));
        return dp[i][j] = ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size(),ans=1;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==-1)
                    ans = max(ans,solve(i,j,matrix,dp));
            }
        }
        return ans;
    }
};