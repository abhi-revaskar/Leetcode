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
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices);
    }
};