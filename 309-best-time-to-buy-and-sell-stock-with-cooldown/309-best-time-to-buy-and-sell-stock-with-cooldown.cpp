class Solution {
public:
    int dp[5001][2];
    int solve(int i,int buy,vector<int> &prices)
    {
        if(i>=prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
        {
            return dp[i][buy] = max(solve(i+1,1,prices),solve(i+1,0,prices)-prices[i]);
        }
        else
            return dp[i][buy] = max(solve(i+1,0,prices),solve(i+2,1,prices)+prices[i]);
    }
    int maxProfit(vector<int>& prices) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,1,prices);
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j)
                    dp[i][j] = max(dp[i+1][1],dp[i+1][0]-prices[i]);
                else
                    dp[i][j] = max(dp[i+1][0],dp[i+2][1]+prices[i]);
            }
        }
        return dp[0][1];
    }
};