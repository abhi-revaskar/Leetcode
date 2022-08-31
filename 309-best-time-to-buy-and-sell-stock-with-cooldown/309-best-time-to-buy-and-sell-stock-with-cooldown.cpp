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
        int n = prices.size(),nxt10=0,nxt11=0,nxt21=0;
        // vector<vector<int>> dp(n+2,vector<int> (2,0));
        for(int i=n-1;i>=0;i--)
        {
            int curr1 = max(nxt11,nxt10-prices[i]);
            int curr0 = max(nxt10,nxt21+prices[i]);
            nxt21 = nxt11,nxt11=curr1,nxt10=curr0;
        }
        return nxt11;
    }
};