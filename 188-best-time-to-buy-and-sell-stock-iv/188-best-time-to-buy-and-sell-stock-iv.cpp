class Solution {
public:
    int dp[1001][2][101];
    int solve(int i,int buy,int k,vector<int> &prices)
    {
        if(k==0 || i==prices.size())
            return 0;
        if(dp[i][buy][k]!=-1)
            return dp[i][buy][k];
        if(buy)
            return dp[i][buy][k] = max(solve(i+1,0,k,prices)-prices[i],solve(i+1,1,k,prices));
        else
            return dp[i][buy][k] = max(solve(i+1,1,k-1,prices)+prices[i],solve(i+1,0,k,prices));
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,k,prices);
    }
};