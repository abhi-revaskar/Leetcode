class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<int> dp(matrix[0].size(),0),prev(matrix[0].size(),0);
        int ans = 0;
        prev=matrix[0];
        for(auto x:prev)
            ans+=x;
        for(int i = 1;i<matrix.size();i++)
        {
            dp[0]= matrix[i][0];
            ans+=dp[0];
            for(int j = 1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    dp[j] = min(dp[j-1],min(prev[j],prev[j-1]))+1;
                    ans += dp[j];
                    
                }
                else 
                    dp[j]=0;
            }
            prev = dp;
        }
        return ans;
    }
};