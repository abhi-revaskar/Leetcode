class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),0));
        int ans = 0;
        dp[0]=matrix[0];
        for(auto x:dp[0])
            ans+=x;
        for(int i = 1;i<matrix.size();i++)
        {
            dp[i][0]= matrix[i][0];
            ans+=dp[i][0];
            for(int j = 1;j<matrix[0].size();j++)
            {
                if(matrix[i][j])
                {
                    dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};